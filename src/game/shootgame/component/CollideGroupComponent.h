#ifndef __COLLIDEGROUPCOMPONENT_H__
#define __COLLIDEGROUPCOMPONENT_H__

enum class ECollideGroup
{
	Bullets,
	Enemies,
	Bombs,
	Lasers
};

/* Defines a  */
typedef std::tuple<ECollideGroup, ECollideGroup> CollideSelector;
typedef (void)(*CollideCallback)();

class CollideGroupComponent {
public:
	CollideGroupComponent ();
	virtual ~CollideGroupComponent ();

private:
	ECollideGroup _cgroup;
};


#endif
