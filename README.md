# THE WORLD FAMOUS (OR INFAMOUS) BOARD FILLER

## SHORT INTRODUCTION

The aim of this project is to create a bot which will fight other bots in the world's famous (or not) game Filler.

The rules are very simple. There is Virtual Machine (VM) wich takes 3 parameters: two opponent bots and a board.
At the beginning of the game VM gives (via stdin) map with 2 dots on it - 'O' and 'X' in accordance for first and second players.
Also it gives random figure which must be placed on the board (you can find example of input information in /test_files folder).
First bot reads the map, analyzes it and gives back the coordinates of next step.

Then VM try to put figure on the board. If it was valid coordinates second bot take updated board and another figure to make next move.
Then it continue again and again.

The game ends when the figure cannot be placed anymore.
So, if one bot gave invalid coordinates another will play until it finds free space on the board.

Every time bot place figure it earns 1 point.
The winner is the one who scored more points.

You can find full description in subject [filler.en.pdf] file.

## DESCRIPTION OF MY IMPLEMENTATION

My Filler bot is divided into 3 parts:
1. Read input data from VM. This functions can be found in src/main.c file. Also example of input data can be found in /test_files.
2. Index all positions on the board according their distance from the opponent bot. File src/index_board_func.c.
This is the most important part, to read more about this algorithm, google **"taxicab geometry"** or **"chebyshev distance"**, or in ukrainian "Манхеттенська метрика" or "Відстань Чебишова".
Here is some screenshots:
[pic1](screenshots/pic1.png)
It looks like my bot surrounds opponent's territory in a circles with numbers from smaller to bigger and this numbers show minimum distance to touch the opponent.
In other words - we can find the value of each free possition on the board to make a dicision where to put figure on the next third step of algorithm.

3. Find next move. File src/find_next_step.c.
For this purpose bot tries to place figure on each place on the board from the upper left to the down right and check whether this possition is valid.

Valid possition must respond the following rules:
  - only one touch with my territory;
  - no touch with opponent territory;
  - the whole figure should fit on the board.

Than bot need to find **the best valid place**. It calculates all indexes wich will be coverd by figure and choose the one with least number.
For this reason it has additional structure *t_cpu* where stored the best coordinates for next move.

That's it!
After all 3 steps bot can print result on stdout (via standard printf).

## HOW TO LAUNCH AND TEST

First clone git repositiry (type in console):
```
git clone https://github.com/Navalag/filler.git filler

```
Than go to the project folder and launch:
```
cd filler

make

./resources/filler_vm -f resources/maps/map01 -p1 ./agalavan.filler -p2 ./resources/players/carli.filler | bash colors.sh

```
You can change map from resources/maps/(map00, map01, map02), opponent bot from /resources/players or you can try it against your own bot.

GOOD FIGHT and
**Enjoy :)**

## HOW TO CONTACT ME

If you found mistake or bug, have any questions or sugestions, plese feel free to contact me via agalavan@student.unit.ua
