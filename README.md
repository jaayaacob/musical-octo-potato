# Hackathon 2 #

### Group 22 Members : ###

1. AHMAD DZULHANIF BIN DZURAIDI  (164249)
2. IQMAL AIDID BIN ZAKARIA       (16)
3. JALAL NAIM BIN MAT YAACOB     (164498)

- [Description of The Game](#description-of-the-game)
- [Features of The Game](#features-of-the-game)
- [How to Play the Game](#how-to-play-the-game)
- [How Object-oriented Concepts were Used to Develop the Game](#how-object-oriented-concepts-were-used-to-develop-the-game)
- [How linked lists play a role in the Game](#how-linked-lists-play-a-role-in-the-game)
- [Screenshots of the Game](#screenshots-of-the-game)
- [A link to your game demo video](#a-link-to-your-game-demo-video)




### Description of The Game ###

**Creature Warfare** is an engaging multiplayer game designed for 2 to 4 players. In this game, players embark on an exciting journey where they must answer challenging mini-game questions to unlock special abilities that allow them to summon powerful creatures.

Every turn, each player possesses a unique set of questions, and successfully answering them grants them the ability to summon their creatures(maximum 3 creatures). These creatures serve as formidable allies in the intense battles that ensue. Players strategically summon their creatures at their respective bases and engage in thrilling combat with other players.

The creature's strengths (attack value), and chances of success were determined by the random number. The outcome of the battles between creatures is also determined by a random number generator that takes into account the creature's individual chances of winning. So, there is a possibility that creatures with a small attack value can win against the creatures that have a big attack value which is a higher chance to be a winner of the battle. This aspect adds an element of both strategy and luck to the game.

**Creature Warfare** provides an immersive experience where players can test their knowledge, strategic thinking, and luck in epic creature battles. With its multiplayer nature and diverse range of creatures, the game offers endless possibilities for intense and engaging gameplay. So gather your friends, summon your creatures, and let the battles begin in this exciting combination of strategy and chance!

### Features of The Game ###

**1. Multiplayer Experience**

"Creature Warfare" is designed to be played with 2 to 4 players, allowing you to enjoy the game with your friends. The multiplayer aspect adds a social and competitive element, making each battle more thrilling and engaging.

**2. Mini-Game Questions**

To unlock abilitiy which is summon creatures, players must answer mini-game questions. For these questions, AI will generate one random number and the player need to guess the number. Answering the questions correctly earns you the ability to summon creatures.

**3. Summoning Creatures**

Successfully answering the mini-game questions grants players the power to summon creatures. Each player has their unique set of creatures (maximum 3 creatures), each with its own strengths (attack value) are generated by the random number. The creatures may belong to different categories based on their powers, such as elemental creatures(attack value = 1), mythical beasts (attack value = 2 & 3), or legendary creatures (attack value = 4 & 5).

**4. Base Building**

Each player has a base where they can summon and manage their creatures. The base serves as a central hub for strategizing and preparing for battles. Once the creatures move outside of the base, its cannot recall to the base to make the game more fun which is forcing the creatures to fight against the other player's creatures. 

**5. Creatures' Battles**

The outcome of each battle between creatures is determined by a random number generator. This generator takes based on the creatures' strengths (attack value) such as creatures with attack value = 1 fight with creatures with attack value = 5, so chance creatures with 1 attack value to win the battle is 1/6% otherwise  5/6%. This element of chance adds an exciting and unpredictable aspect to the game, requiring players to balance their strategies with a bit of luck.

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
   - Each players only can move one creatures to the same room which mean two creatures of one player in one room is forbidden
5. If there are two creatures from different players in the same room, they will fight for elimination by generating random numbers based on their attack value.
6. When one of the creatures move to the position 5,
   - There is a counter to check the win condition of the game
   - The counter will start counting if the same creatures still staying in the room 5 on the second round after its moved to that room
   - Once counter reached 3, so the player of that creature is announced as a **winner of the game**

### How Object-oriented Concepts were Used to Develop the Game ###

### How linked lists play a role in the Game ###

### Screenshots of the Game ###

### A link to your game demo video ###
