# Mazegame
1. Randomly Generated Maze:

The maze is dynamically created at runtime with randomly placed:

Treasure (T)

Obstacles (O)

Enemies (E)

Doors (char 219)

The boundaries of the maze are represented by -.

2. Player Mechanics:

The player starts at a fixed position (1,1) represented by P.

Initial health is set to 10.

Players can move in four directions:

u (up)

d (down)

l (left)

r (right)

3. Health and Game State:

Interacting with certain elements in the maze affects the player's health:

Obstacles (O):

Reduce health by 1.

Display a warning.

Enemies (E):

Trigger a number-guessing mini-game.

Winning increases health by 3, losing reduces health by 4.

Doors (219):

Increase health by 5.

Boundaries (-):

Attempting to cross reduces health by 1.

4. Winning and Losing:

The player wins upon finding the treasure (T).

The game ends if the player's health reaches 0.

Code Overview:

Key Functions:

generatemaze()

Initializes the maze with empty spaces.

Places boundaries, treasure, obstacles, enemies, and doors randomly.

printmaze()

Displays the current state of the maze in the console.

moveplayer(int dx, int dy)

Handles player movement and interactions with maze elements.

Updates the maze to reflect the player's new position.

Checks for collisions and adjusts health accordingly.

defeatenemy()

Implements a mini-game for enemy encounters.

The player guesses a number; health is adjusted based on the result.

Main Function

Handles game loop:

Accepts user input for movement.

Checks for game-ending conditions (treasure found or health depleted).

Displays updated maze and health after each move.

How to Run

Clone the repository:

git clone https://github.com/yourusername/maze-adventure-game.git

Navigate to the project directory:

cd maze-adventure-game

Compile the code using a C++ compiler (e.g., g++):

g++ -o maze_game maze_game.cpp

Run the executable:

./maze_game

Gameplay Instructions

Use the following keys to move:

u: Move up

d: Move down

l: Move left

r: Move right

Avoid obstacles and enemies, and manage your health.

Find the treasure to win the game.

Keep an eye on your health; the game ends if it drops to 0.

Sample Output

Enter a direction(u,d,l,r): r
You hit an obstacle!
Your current health is: 9
---------------------
- P       O         -
-         T         -
- O                 -
-         E         -
---------------------

License

This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments

This project is a beginner-friendly implementation of a maze game to practice fundamental programming concepts such as:

Arrays

Random number generation

User input

Game loops

Conditional logic

