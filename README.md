CardGame
========

Made a LinkedList for practice then decided to make a deck out of it... then why not play some Card Games with it?

Goal: Apply and thus internalize concepts from Code Complete 2 (Practicing Design and language contructs)

Concepts:
Design such as abstraction, encapsulation, polymorphism, inheritence, coupling, cohesion...
-Central points of control (ie all db connections in one class/package)

Design:
Card -> LinkedList -> Deck -> Session ->  GameLogic (5card draw)
                    -> Hand -> Session -> Player
                            Session -> UI

*Session is central module*
May want to give phases their own class?

Todo:
Unit Testing
GUI (non CLI)
