ofxTexturePacker
==============

![Screenshot](https://github.com/danoli3/ofxTexturePacker/raw/master/ofxaddons_thumbnail.png)

OpenFrameworks addon for loading and rendering sprites and animated sprites generated from CodeAndWeb's TexturePacker appliation.

What is TexturePacker?
----------------

- Allows quick creation of sprite sheets with reference name of the original image
- Optimises rendering speed and memory usage of an App or Game
- Mutli-OS (OSX,Linux,Windows)
- Supports generating sprite sheets for different targets automatically (i.e. retina and non-retina)

What is a Sprite Sheet?
http://www.codeandweb.com/what-is-a-sprite-sheet

Get Texture Packer (has free to use version)
http://www.codeandweb.com/texturepacker

Why use this addon?
-------------------

- Easy intergration.
- Saves memory
- Optimises rendering
- Supports animation


How to refactor an ofImage into ofxTPSprite:
```
// Turn:
ofImage * normal = new ofImage();
normal.loadImage("images/normal.png");
// Into:
ofxTPSprite * normal = texturePacker.getSprite("images/normal.png");

```

Still a work in progress. Will be maintained.

