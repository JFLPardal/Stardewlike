# Stardewlike
Small project where I create some of the mechanics of Stardew Valley using C++ and SFML

## High level tasks for this project and their current state:

 ### Engine
 * [x] Event system (homebrewed, it has some flaws)
 * [x] Game Objects are the base entities of the game and they have a collection of components
 * [x] Components have a single responsibility and purpose, they are added to a Game Object based on that GO's purpose (these include Transform, SpriteRenderer, Animator, StateMachine, etc...)
 * [ ] Time representation (used for example to influence the growth of the plant)
 * [ ] Collision detectition
 
 ### Player Animations
 * [x] Player's sprite change based on the direction of the mouse position
 * [ ] Complete Animations of walking and idling
 
 ### Player Actions
 * [x] Player can walk
 * [x] Player can interact with a tile on the map
 * [x] Player can change the item being held
 
 ### Inventory
 * [x] Player has an Inventory that holds all of his items
 * [x] Player as an item being held, which he uses to interact with the world
 * [ ] UI showing the player's inventory
 * [ ] UI showing the current held item
 
 ### Interactables (Entities that the World or Player can have on his Inventory like Tools and Seeds)
 * [x] Seeds can be added to the map if there is nothing on that tile
 * [ ] Seeds grow to Plants after some time has passed and they have been watered
 * [ ] Plants can be picked up and are added to player's inventory
 * [x] Hoe can destroy Seeds that are on a given tile of the map
 * [ ] Watering Can will water Seeds that will make them grow when a day is over
 
### Tilemap
 * [x] Tilemap is drawn
 * [ ] Create a proper tilemap
 
