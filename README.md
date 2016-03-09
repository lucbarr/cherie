# cherie

This is a coding project made for the sake of studying finite state machines' artificial intelligence implementation and practicing object oriented programming in C++. Here are few explanations about the initial concept:

# who is cherie ?

Cherie is a dog. I asked a friend of mine if she could describe her canine fellow Cherie so I could design the animal as a finite state machine. She told me basically what her dog does all day, so I could turn her into an actual machine. Cherie has some simple states:

# cherie's states:

*lain : cherie sleeps a lot.
*scrathing : cherie scratches herself 90% of the time.
*begging : cherie begs for food while her owners eat.
*pissing : cherie pisses a lot on the carpet. A lot.
*eating : cherie eats
*drinking : cherie drinks

# cherie's transitions (may change)
*to scratching from any : cherie swipes her paws into her own fur
*to eating from begging : cherie jumps into the air and bites a piece of food
*to eating from any but lain : cherie heads towards her food bowl
*to drinking from any but lain : cherie heads towards her water bowl
*from lain to any : cherie yawns and stretches her legs
*to pissing from begging : cherie pisses and gets her Anna very mad
*to pissing from any : cherrie goes to the living room, sit down and pisses a lot on carpet.
