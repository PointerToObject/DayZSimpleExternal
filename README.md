# DayZ simple console external  
What's up guys. I made this simple console external but with a lot of help from a friend of mine. I've been relearning C++ and basic reverse engineering since 2/26/2024, and I've been motivated since to learn how to create game hacks. My end goal is to create a youtube channel, so I can teach C++ and game hacking, so everyone wont have to go and ask 40399288 questions on 35 different servers just to get muted or kicked or all that bs. anyways let me get onto this cheat.

Extremely simple external that I will be updating frequently. Currently a console cheat, Utilizes the up,down,left,and right arrows.
Update 4/30/2024 - cleaned the source up, added far table, stopped making it read 3 rpm's at once and just made it re-read the world class. also changed output to only output when something changes.

How To Use

           : Up/Down Arrow to scroll through the list

           : Left/Right Togle on/increase/decrease

Features     
  
         : Eye Accom adjuster(basically turns night to day, pictures below)
         : Near Animal Table count(shows all entites that are alive on the near table)
         : Bullet Table Count(Shows all the bullets currently in the air after being shot{will dissapear after landing})
         : Goals Below : 
goals:
1. add far animal table feature ( added )
2. seperate players and zombies within near/far animal table like this in psudo

	Near Animal Table (Zombie)	: 6
	Near Animal Table (Player)	: 2
	Far Animal Table (Zombie)	: 11
	Far Animal Table (Player)	: 8
3. find the coordinates of my local player and output it
4. find the coordinates of players/zombies/bullets
5. add imgui or something else for an overlay and make an overlay for the cheat
6. draw the bullets on the screen
7. draw the players and zombies on the screen
8. make item esp
   
                       Before eye accom is toggled on
![11](https://github.com/PointerToObject/DayZSimpleExternal/assets/164882065/a8828f37-2166-4590-9969-87df8524f120)

         after :D
![2](https://github.com/PointerToObject/DayZSimpleExternal/assets/164882065/df9413ad-9a80-48da-bcb6-630b02516db3)
