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

The ability to summon a creature and the creature's attack value is determined by the random number generator (RNG). The outcome of the battles between creatures is also determined by a random number generator that takes into account the creature's individual chances of winning. Thus, there is a possibility that a creature with a low attack value can attain victory against a creature with a high attack value despite it having a drastically lower chance of winning. This aspect adds an element of both strategy and luck to the game.

The goal of the game is to have a creature remain inside the centre room for a specific duration, without it being eliminated by the other player's creatures during that time span.

**Creature Warfare** provides an immersive experience where players can test their knowledge, strategic thinking, and luck in epic creature battles. With its multiplayer nature and diverse range of creatures, the game offers endless possibilities for intense and engaging gameplay. So gather your friends, summon your creatures, and let the battles begin in this exciting combination of strategy and chance!

### Features of The Game ###

**1. Multiplayer Experience**

"Creature Warfare" is designed to be played with 2 to 4 players, allowing you to enjoy the game with your friends. The multiplayer aspect adds a social and competitive element, making each battle more thrilling and engaging.

**2. Mini-Game Question**

To unlock the ability to summon a creature, players must answer a mini-game question correctly. For this question, the program will generate a random number and the player needs to guess the number. Answering the question correctly earns them the ability to summon a creature for that turn. Guess it wrong, and they will be unable to summon a creature.

**3. Summoning Creatures**

Successfully answering the mini-game question grants players the ability to summon a creature. Each player has their own unique set of creatures, each with its own strengths (attack value) generated by the random number generator. 

**4. Base Building**

Each player has a base which serves as the spawn point of their creatures. This base is delegated to each player at the start of the game and remains as is for the entirety of the game. Once a creature moves outside of its base, it cannot return to its base and will have to proceed onward onto battle.

**5. Creatures' Battles**

When two opposing creatures are together inside a room. The outcome of each battle between creatures is determined by a random number generator. This generator takes based on the creatures' strengths (attack value) such as creatures with attack value = 1 fight with creatures with attack value = 5, so chance creatures with 1 attack value to win the battle is 1/6% otherwise  5/6%. This element of chance adds an exciting and unpredictable aspect to the game, requiring players to balance their strategies with a bit of luck.

**6. Strategy and Luck**

**Creature Warfare** combines strategic decision-making with luck-based outcomes. While players can plan their battles and optimize their creature selections, the randomized nature of combat means that even the strongest creatures may not always guarantee victory. This blend of strategy and luck keeps the game exciting, as players must adapt and make tactical decisions on the move.

**7. Endless Possibilities**

With a variety of creatures, mini-game questions, and multiplayer dynamics, "Creature Warfare" offers endless possibilities for gameplay. Each battle is a unique experience, and players can experiment with different strategies, creature combinations, and play styles to gain an edge over their opponents.


### How to Play the Game ###

1. User needs to determine how many people want to play the game.
2. Every player has their own base.
   - Base player 1 is at position 1
   - Base player 2 is at position 3
   - Base player 3 is at position 7
   - Base player 4 is at position 9
3. The players need to guess the correct answer for the question provided in the minigame.
   - If correct, then the player can summon one creature and the game randomize the attack value of the creature.
4. Movement of the Creatures:
   - The players only can move their creature to the other position in a straight line
   - Move creatures to the other positions diagonally is forbidden
   - Once creatures move outside of the base, its cannot recall to their own base
   - Each player only can move one creature to the same room which means two creatures of one player in one room are forbidden
5. If there are two creatures from different players in the same room, they will fight for elimination by generating random numbers based on their attack value.
6. When one of the creatures moves to position 5,
   - There is a counter to check the win condition of the game
   - The counter will start counting if the same creatures still staying in room 5 on the second round after it's moved to that room
   - Once the counter reached 3, the player of that creature is announced as a **winner of the game**

### How Object-oriented Concepts were Used to Develop the Game ###



### How linked lists play a role in the Game ###

### Screenshots of the Game ###

### A link to your game demo video ###
