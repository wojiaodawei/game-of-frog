# Frog's game

~~ *This project was implemented in November 2016* ~~

Game with a graphical user interface in which a frog must start from a position to join another one by jumping from water lily to water lily on a pond.

The time of a game is limited to one minute.


In the application model, each type of surface element has a different effect on the frog, these effects are modelized via the design pattern **Strategy**.
The whole application is based on a **Model-View-Presenter** (MVP) architecture.


There are:
* a pdf file *rules_in_French.pdf* describing exhaustively the rules of the game in French
* a *src* directory containing fully commented sources in *Doxygen* format (packages, classes, attributes, methods)
* a compilation script *cmake*
* a *doxyfile* for automatically generating the documentation in HTML format
* a *UML* directory containing the class diagram of the whole application in dia format
