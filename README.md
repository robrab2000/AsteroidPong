# asteroidPong!

It does just what it says on the tin.. it's asteroidPong! combining some of the funnest aspects of those classic 70's arcade >>>SMASH HITS<<< Asteroids and Pong!

produced by: Rob Homewood

## Concept

The idea was to take two classic games that are fun, deconstruct them, and by combining them, see if I could increase how fun they are.

## Originals

Originally released in 1972, Pong was the first commercially successful video game to be released. It featured two very low-fidelity characters, essentially just a rectangular block of pixels), called 'paddles' which the player could move along a vertical axis. A ball, once again simply small a blob of clustered pixels, would bounce between the left and right hand sides of the screen. The aim was to get the ball past the enemy paddle whilst deflecting the ball using your own. If the ball did manage to go past your paddle and exit the side of the screen, your opponent would be awarded a point and vice versa.

Asteroids, slightly more recent having been released in 1979, was also extremely successful. The game took place in space where the player took command of a small space ship surrounded by floating asteroids. The goal was to eliminate all of the asteroids by shooting at them however, each asteroid that got destroyed would break into smaller asteroid fragments which would start flying around screen swiftly creating a cacophony of hazards for the player to avoid.

## Feature Blending

I chose to take the core gameplay from Pong because of its simplicity and because I thought that it would be a better experience, integrating elements from asteroids into the gameplay of Pong rather than the other way around. From Asteroids, I decided to take what I felt was the salient feature which was the collisions and breakdown of larger asteroids into smaller ones.

## Control Interface

The blended game is controlled from an iOS device running a custom layout for the TouchOSC app. I tried several prototype layouts for this including rotary controls that closer resembled the original pong controls but felt that the sliders were simple and intuitive and ultimately led to a better experience. The game features 2 control sliders, one for each player, and a single 'release' button which is shared by the two players which launches the ball from the paddle. The controller also acts as part of the UI, displaying the player's score in real time.

## Artificial Intelligence

As I wanted the game to be playable by both one or two players, I needed an agent to control the second player when there was only one human player. I went for a very simple system which defines a range around the ball's vertical position and then oscillates within this range using a noise function. It presents a somewhat easy challenge but exhibits some lifelike hesitancy and indecision which helps make the experience feel more organic. This is particularly highlighted by feeding the ai's movements back to the OSC controller.

## Aesthetic

My original idea was to go for a very colourful game with lots of strange effects and interesting colours. I decided however to rather go for a more original look that was in line with the capabilities of 70’s computer hardware. As such the game is monochromatic, featuring solid objects for the Pong elements and wireframe white objects for the Asteroids elements of the game, both in accordance with their original games.

## Audio

Like the visual quality, I chose to go for a very low-fidelity solution, locating 8-bit sounds and music to go with the game. Although both original games most likely only featured a mono soundtrack, I stereo sseparated all of the sounds in the game (based on their location on the screen) to increase the player's feeling of immersion.

## Results

Although more user testing, tuning, bug fixes and a few more features could really make this game shine, I still feel that it is quite fun to play and it has achieved its goal.

## References

All of the code written was by myself however a few lines of code were based on examples found in the ofBook and our lecture series but never copied/pasted directly. Music and sound for the game were sourced online from creative commons sources and are listed per sound file in the code.
