This is a fan made project of **Superliminal** by **PillowCastle**. This project was made for **2023 Github Game Jam**, you can play the game over on

**Itch.io:** https://jangomango2001.itch.io/superliminal-psx

or

**Gamejolt:** https://gamejolt.com/games/SuperliminalPSX/859059

Retro styling and shaders were made by **Daveface**, you can get the retro shader project from here https://github.com/DaveFace/UnrealRetroShaders.

Main tutorial by PastaNoob, you can find his tutorial over here https://www.youtube.com/watch?v=Em8hSFAamYo

## Engine
**Minimum engine version:** Unreal Engine 4.27
You can use ue5 as well but turn off TSR, lumen and nanite. The retro shader won't work properly in editor viewport but it should work fine in packaged build.

## Main Components

Most of the core project files are located in the `Content/Superliminal` folder. This directory contains the player character blueprint, props, portal, audio assets, and the central Blueprint Interface (`BPI`) that communication across all systems.

<img width="1216" height="324" alt="{C87C8E49-3742-4E38-AEF0-B6DBFD1A7DEA}" src="https://github.com/user-attachments/assets/81429537-f5ca-4c4a-81b7-bc0e143b0bb1" />

---

### 👤 My_Character
The central player character blueprint handling movement controls and the core **forced perspective** (object scaling based on distance) logic. 

Forced perspective logic is written in **C++** for best performance. However a **Blueprint Friendly:** For people who prefer not to touch C++, a fully functional **Blueprint equivalent function** is included within the event graph for easy debugging and modification.

<img width="600" height="325" alt="Perspective Illusion comp" src="https://github.com/user-attachments/assets/8a7e7678-a0db-4002-954a-94c03b2f5fbe" />

---

### 📦 BP_Master_Prop
The base parent class for all interactive objects in the game. It handles physics states and player interaction events (grabbing, dropping etc). 

Several  variables are exposed to the **Details Panel** for quick, per-instance level design tweaks:
*   `Is Duplicating Prop` (Boolean): When enabled, attempting to grab the object spawns an exact duplicate near the player.
*   `Is Locked` (Boolean): Disables player interaction entirely and turns off physics simulation.

<img width="1187" height="480" alt="{65FD66B2-049F-4695-B84A-FFBCCFF3E207}" src="https://github.com/user-attachments/assets/2e11c7f9-240f-4963-b2e7-13ca66615168" />

---

### 🎨 BP_Projection
This blueprint handles the optical illusion where a 2D image is projected onto the environment, and can be turned into a physical 3D object when viewed from the correct angle.

*   **Setup:** Drop the blueprint into your level, use the Details Panel to assign the target prop, and select the specific walls/surfaces you want to project the 2D decal onto.
*   **Mechanic:** The blueprint continuously checks the player's camera alignment when they get close. Once the player stands at the exact perspective sweet spot, the projection "releases"—instantly spawning the prop and clearing the 2D projection.
*   **Customization:** You can toggle off the release mechanic in the Details Panel.

<img width="600" height="325" alt="Projection Illusion Comp" src="https://github.com/user-attachments/assets/b9bfc9aa-fbcf-4a02-a52c-81de44c6087d" />

---

### 🌀 BP_Portals
Manages seamless non-Euclidean portal rendering and player teleportation. Because it inherits directly from `BP_Master_Prop`, portals can be dynamically picked up, carried, and scaled using the player's forced perspective.

*   **Setup Guide:**
    1. Place two instances of `BP_Portals` into your level.
    2. Select one portal and check the **`Is Primary`** boolean in its Details Panel.
    3. Use the dropdown picker to link the two portals together. This establishes the render-target perspective link and enables teleportation.
*   ⚠️ **Critical Warning:** Do *not* enable `Is Duplicating Prop` on portal blueprints. Portal replication is not nsupported and may break portal logic.

<img width="800" height="436" alt="image" src="https://github.com/user-attachments/assets/8dd246b7-5c2f-4ee6-a309-a1d6652b5167" />

---
## 📃 Credits
* UE4 Retro Shader by Dave Face
* Retro Meshes by Elbolilloduro
* Arcade Floor Texture from OpenGameArt
* Footsteps & Hit Sounds by Bartosz Kamol Kaminski
* Pop Audio from Mixikit
* Meshes from elbolilloduro on Itch
* Piano by Wufudufu from free3d
* PastaNoob for Superliminal UE5 Guide
