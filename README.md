# Hackathon 2 #

### Group 22 Members : ###

1. AHMAD DZULHANIF BIN DZURAIDI (164249)
2. IQMAL AIDID BIN ZAKARIA (16)
3. JALAL NAIM BIN MAT YAACOB (164498)

- [Description of The Game](#description-of-the-game)
- [Features of The Game](#features-of-the-game)
- [How to Play the Game](#how-to-play-the-game)
- [How Object-oriented Concepts were Used to Develop the Game](#how-object-oriented-concepts-were-used-to-develop-the-game)
- [How linked lists play a role in the Game](#how-linked-lists-play-a-role-in-the-game)
- [Screenshots of the Game](#screenshots-of-the-game)
- [A link to your game demo video](#a-link-to-your-game-demo-video)




### Description of The Game ###

**Creature Warfare** is an engaging text-based multiplayer game designed for 2 to 4 players. In this game, players have to confront each other in battles between using their creatures, fighting to determine who would emerge victorious in a 'King of the Hill' style gameplay.

Every turn, the player is given a simple minigame-like question, and successfully answering it grants them the ability to summon a creature. These creatures serve as formidable allies in the battles that ensue. Players summon their creatures at their respective bases and strategically engage in combat with other players.

The ability to summon a creature and the creature's attack value is determined by the random number generator (RNG). The outcome of the battles between creatures is also determined by a random number generator that takes into account the creature's chances of winning. Thus, there is a possibility that a creature with a low attack value can attain victory against a creature with a high attack value despite it having a drastically lower chance of winning. This aspect adds an element of both strategy and luck to the game.

The goal of the game is to have a creature remain inside the centre room for a specific duration, without it being eliminated by the other player's creatures during that period.

**Creature Warfare** provides an immersive experience where players can test their knowledge, strategic thinking, and **luck** in epic creature battles. With its multiplayer nature and diverse range of creatures, the game offers endless possibilities for intense and engaging gameplay. So gather your friends, summon your creatures, and let the battles begin in this exciting combination of strategy and chance!

### Features of The Game ###

**1. Multiplayer Experience**

"Creature Warfare" is designed to be played with 2 to 4 players, allowing you to enjoy the game with your friends. The multiplayer aspect adds a social and competitive element, making each battle more thrilling and engaging.

**2. Mini-Game Question**

To unlock the ability to summon a creature, players must answer a mini-game question correctly. For this question, the program will generate a random number and the player needs to guess the number. Answering the question correctly earns them the ability to summon a creature for that turn. Guess it wrong, and they will be unable to summon a creature.

**3. Summoning Creatures**

Successfully answering the mini-game question grants players the ability to summon a creature. Each player has their own unique set of creatures, each with its strengths (attack value) generated by the random number generator. 

**4. Base Building**

Each player has a base which serves as the spawn point of their creatures. This base is delegated to each player at the start of the game and remains as is for the entirety of the game. Once a creature moves outside of its base, it cannot return to its base and will have to proceed onward onto battle.

**5. Creatures' Battles**

When two opposing creatures are together inside a room, they enter a battle for elimination. The outcome of each battle between creatures is determined by a random number generator. This generator takes based on the creatures' strengths (attack value) such as a creature with attack value = 1 fighting against a creature with attack value = 5. Thus, the chance for the creature with 1 attack value to win the battle is 1/6. This element of chance adds an exciting and unpredictable aspect to the game, requiring players to balance their strategies with a bit of luck.

**6. Strategy and Luck**

**Creature Warfare** combines strategic decision-making with luck-based outcomes. While players can plan their battles and optimize their creature selections, the randomized nature of combat means that even the strongest creatures may not always guarantee victory. This blend of strategy and luck keeps the game exciting, as players must adapt and make tactical decisions on the move.

**7. Endless Possibilities**

With a variety of creatures, mini-game questions, and multiplayer dynamics, "Creature Warfare" offers endless possibilities for gameplay. Each battle is a unique experience, and players can experiment with different strategies and play styles to gain an edge over their opponents.

**8. Save/Load**

Does an emergency occur during a game? You can ask the host to terminate the program at the beginning of the next player’s turn by choosing the option **"Save and Exit Game"**. The program will always save the game’s data at the end of every player’s turn and record it into a .txt file. This utilises each player’s linked list as the program traverses to input the data into the .txt file. 
*Note: The player whose turn is used to save and exit the game, data for that turn will not be recorded meaning that if a creature was summoned, it will not be saved. However, after loading the previous game, they will be able to summon a creature again as the game saved before their turn begins.*

On the next run of the program, the host can choose to load the previous game’s data into the game. From the .txt file, each player’s creatures are appended into their linked list and other game data is reinitialised. Hence, players can continue playing from where they last left off.


### How to Play the Game ###

1. User needs to determine how many people want to play the game.
2. Every player has their own base.
   - Player 1's base is in Room 1
   - Player 2's base is in Room 3
   - Player 3's base is in Room 7
   - Player 4's base is in Room 9
3. The players need to guess the correct answer for the question provided in the minigame.
   - If correct, then the player can summon one creature and the game randomizes the attack value of the creature between 1 to 5.
4. Movement of the Creatures:
   - The players can only move their creature to another nearby room horizontally or vertically.
   - Moving a creature to another room diagonally is forbidden.
   - Once a creature moves outside of its base, it cannot return to its base.
   - Each player can only move one creature to a singular room which means two creatures of the same player cannot reside in the same room at a time.
5. If there are two creatures from different players in the same room, they will fight for elimination by generating random numbers based on their attack value.
6. When one of the creatures moves to position 5:
   - Each player has a counter that keeps track of how many turns their creature has resided in Room 5.
   - The counter will increase at the start of a player’s turn if they own a creature inside Room 5 at that moment.
   - If the creature perishes in a battle against another enemy creature, the counter resets to 0.
   - Similar to ‘King of the Hill’, once the counter reaches 3, the player who is the owner of the creature in Room 5 is declared **the winner of the game.**


### How Object-oriented Concepts Were Used to Develop the Game ###

Classes: The game utilizes several classes, such as Player and CreatureList. These classes encapsulate related data and functions, allowing for modular and organized code.

Encapsulation: The classes encapsulate data and behaviours within themselves, providing abstraction and separation of concerns. For example, the Player class encapsulates player-related information and functions.

Polymorphism: Can be used to create different players or creatures that can be treated uniformly through base class pointers or references. Each player has their own set of unique creatures within their respective linked lists.

Inheritance: Inheritance can be used to create derived classes that inherit properties and behaviours from base classes. This can be useful for creating specialized player types or creature types in the game. **Unfortunately, we were unable to implement this in our program.**


### How linked lists play a role in the Game ###

In "CreatureList.h", a class called CreatureList is defined, which represents a linked list of creatures. It contains private data members for the creature's ID, name, attack value, position, and a pointer to the next node within the struct CreatureNode, where a node represents a unique creature. 

The class provides various member functions for manipulating the linked list, such as adding a new creature, deleting a creature, retrieving creature information, changing creature positions, and more. 

The linked list is essential to the game as it dynamically allocates a sufficient amount of memory to represent a creature as a Node. Unlike arrays where it is required to allocate a certain amount of memory, the usage of a dynamic linked list prevents excessive memory allocation. It also prevents the cases where the size of the array is not enough to store all the creature data as the linked list is more flexible and can grow or shrink at any time.

Most importantly, the linked list is essential for the process of saving the data of the game into a .txt file and using the .txt file to load the linked list with the previous game’s data on the next instance of the program. 
The game’s data is recorded into the .txt file at the end of a player’s turn. If the player decides to terminate the program to continue at a later time, they can run the program once again and choose to load the previous game’s data through the linked list.


### Screenshots of the Game ###

![image](https://github.com/jaayaacob/musical-octo-potato/assets/137621915/e37dedfc-3248-4497-9730-224e442ad096)
![image](https://github.com/jaayaacob/musical-octo-potato/assets/121543534/383444f1-d67c-4f2e-b50f-2914b9ae320c)


### Link to game demo video ###
[Creature Warfare Demo] (https://www.youtube.com/)
