# Laetus 3 Documentation ( WORK IN PROGRESS )

![Laetus Icon](https://i.imgur.com/VLQ2Q0Y.png =250x)

**Please Note: This document is a work in progress.**

This documentation page details how to create themes for Laetus 3!

Laetus 3 supports three different types of themes:
- Image Themes
- HTML Themes
- Hybrid Themes

## Image Themes
Image themes are simply themes constructed using purely images. These images need to be formatted in the correct way, both in size and in file name.
There are various files you can provide, all of which are optional.

### Image Theme Names
Full list of possible file names:
```
KeyboardMainBG - This image is used as the background behind the keys.
KeyboardNumbersBG - This image is used as the background behind the number keys (If not provided KeyboardMainBG is used).
KeyboardEmojiBG - This image is used as the background behind the emoji keys (If not provided KeyboardMainBG is used).
KeyboardDictationBG - This image is used as the background behind the dictation keys (If not provided KeyboardMainBG is used).
KeyboardPredictionBarBG - This image is used as the background behind the prediction keys.
KeyboardLettersKeyPlane - This image is used on the letters screen, above the background (The backgrounds behind the key letters).
KeyboardNumbersKeyPlane - This image is used on the numbers screen, above the background (The backgrounds behind the key letters).
KeyboardPressedKeyCap - This image is used behind the key popup when tapping on a key (Experimental).
```

### Image Theme Name Formatting
All of the images listed above can have extra filters applied to them to give a better experience to the end user. This information can be provided as part of the file name as so:
```
{IMAGE_NAME}[Portrait|Landscape][-{REGION}][-{SCREEN_HEIGHT}h].png
```
For example, if you wanted to provide a different "KeyboardMainBG" for Portrait and Landscape you could do:
```
KeyboardMainBGPortrait.png
KeyboardMainBGLandscape.png
```
Or to provide a different keyplane for a specific language (for example UK English - en_GB), you could provide:
```
KeyboardLettersKeyPlanePortrait-en_GB.png
KeyboardLettersKeyPlaneLandscape-en_GB.png
```
Or maybe you only want that image to be used on an iPhone X?
```
KeyboardLettersKeyPlanePortrait-en_GB-812h.png
KeyboardLettersKeyPlaneLandscape-en_GB-812h.png
```


