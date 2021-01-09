# TicTacToe

This is an updated version of my original TicTacToe game. It's been 3 years since I pushed the first commit and I have updated essentially everything.

The first game had bugs that went unnoticed and it was horribly organized. Many functions did not make sense and there were no comments. 

While the new commit is an improvement, I still want to add the seperation of the Player and Bot class instead of having them as one player object. I could still take advantage of the shared_ptr < Player > to refer to the objects  but have a derived Bot class that overrides the determineMove function. This would be better than having a determingBotMove in the private of Player. 