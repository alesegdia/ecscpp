
# Basic concepts

## What is an entity?

An entity is used to define gameobjects living in our game world.
An entity could be the player, a flying pig pet, an evil undead kitten
or a powerup.

## What is a component?


A component is just a piece of data that defines an aspect of
the entity it is associated to. A component can be a RenderComponent,
defining how the entity is visualized at screen by holding a sprite,
or a PhysicComponent, containing a Box2D body that defines physical
properties of that entity.

## What is a system?

A system performs a bit of logic on each entity by running
continuously in our game. A system could be a TriggerWeaponSystem
that checks if has passed enough time to shoot a weapon depending
on the last shot time and the rate of fire. A more simple and
straightforward example could be a RenderingSystem, that takes
RenderComponent and PhysicComponent and draws on screen the entity
sprite in proper coordinates.

# Design specifics

## How are components and entities glued together?

In this implementation, an entity is an object composed of an **eid**
identifier and a *std::unordered_map* to keep track of components.

Each entity has a **flags** member that keeps info on what
components the entity has. This is intended for performant checking
of an entity having certain component types.

Each component's flag needs to be manually defined at
*component/ComponentFlags.h*, having a maximum of 32 different
components. This constraint comes from the **cflags_t** type being
an **uint32_t**, but it can be easily changed.

## How is logic done?

So components are just data. To define some logic we have the
*System* interface, that is supposed to be inherited to achieve more
concrete ways of processing logic. For example, you could want a
system that needs to process entities in some order, or you may want
to process them all caring zero about order.

### How do entity processing systems handle entities?

Currently, an *EntityProcessingSystem* was coded to process entities
in no particular order. To keep good design manners, an *EntityObserver*
interface was created to define semantics for a class that wants
to be notified when an entity is added or deleted inside our game world.
So *EntityProcessingSystem* class inherit from *System* and *EntityObserver*
interfaces.

### How is entity processing done within EntityProcessingSystem?

The *EntityProcessingSystem* class just keeps track of entities
that it's interested in depending on the components it has. To achieve this,
previously stated **Entity::flags** is used with the concrete system
needed flags to check if it is needed.

# Restrictions

* Only 32/64 max. components

* Only 1 component of each type supported.

# Possible improvements

* Increasing component maximum number to unlimited by using some
bitset class instead of using a plain integer (**cflags_t**).

* Create a script that generates the *components/ComponentFlags.h*
file instead of having to fill it manually.
