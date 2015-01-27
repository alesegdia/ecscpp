
#!/usr/bin/env bash

python gencomp.py shootgame.json
mv Component* ../src/game/shootgame/component
