# Laetus 3 Documentation

<img src="https://i.imgur.com/VLQ2Q0Y.png" width="200">

**Please Note: This document is a work in progress.**

## Introduction

This documentation page details how to create themes for Laetus 3!

**Laetus is temporarily only available to SparkDev Members or designers.**
**If you are a known designer/web developer please contact me on my Discord server and I'll happily give you access.**

**[Join SparkDev's Discord](https://discord.gg/UJ4dWPv)**


## Themes

Laetus themes are stored in ```/Library/Laetus/Themes```

Laetus 3 supports three different types of themes:
- [Image Themes](#image-themes)
- [HTML Themes](#html-themes)
- [Hybrid Themes](#hybrid-themes)

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

Images can be provided with a scale also (remember to scale the image appropriately for best results).
```
KeyboardLettersKeyPlanePortrait-en_GB-812h@3x.png
```

### Image Theme Sizes
The best sizes will differ from device to device, particularly for the keyplanes (Which may also differ across languages).

I will be populating this section as I learn the best sizes for different screens:

```
Notched Plus Devices (e.g. XS Max, 11 Pro Max):
    Screen Height: 896
    Main BG Portrait @3x: 1242 × 906
    Main BG Landscape @3x: 2688 × 513
    Prediction Bar BG Portrait @3x: 1242 × 135
    Prediction Bar BG Landscape @3x: 1986 × 114

Notched 3x Devices (e.g. X, 11 Pro):
    Screen Height: 812
    Main BG Portrait @3x: TODO
    Main BG Landscape @3x: TODO
    Prediction Bar BG Portrait @3x: TODO
    Prediction Bar BG Landscape @3x: TODO

Notched 2x Devices (e.g. XR, 11):
    Screen Height: 812
    Main BG Portrait @2x: TODO
    Main BG Landscape @2x: TODO
    Prediction Bar BG Portrait @2x: TODO
    Prediction Bar BG Landscape @2x: TODO

Non-Notched Plus Devices (e.g. 7 Plus, 8 Plus):
    Screen Height: 667
    Main BG Portrait @3x: TODO
    Main BG Landscape @3x: TODO
    Prediction Bar BG Portrait @3x: TODO
    Prediction Bar BG Landscape @3x: TODO

Non-Notched 2x Devices (e.g. 7, 8):
    Screen Height: 667
    Main BG Portrait @2x: TODO
    Main BG Landscape @2x: TODO
    Prediction Bar BG Portrait @3x: TODO
    Prediction Bar BG Landscape @3x: TODO

Non-Notched Small 2x Devices (e.g. SE-1):
    Screen Height: 568
    Main BG Portrait @2x: TODO
    Main BG Landscape @2x: TODO
    Prediction Bar BG Portrait @3x: TODO
    Prediction Bar BG Landscape @3x: TODO
```

I will be putting together an example pack containing empty images for all of these sizes very soon.

### Image Theme Format
As with all Laetus themes, the theme should be a folder in ```/Library/Laetus/Themes```.
Images of the theme must be stored in a sub-folder called ```Images```

This GitHub repository includes an example theme showing the structure and some example images. However, the structure looks as follows:

![Image Theme Structure](https://i.imgur.com/Ik3lSoM.png)

Themes can then be packaged into a deb file the same way traditional iOS themes are (e.g. for SnowBoard or other theming engines).

## HTML Themes
HTML themes are essentially simply a web page shown behind the keyboard, but Laetus provides more power to this webview to make it more interesting. 

An example of an HTML theme could be as simple as a HTML page (Named "index.html") like so:
```
<html>
    <head>
        <meta name="viewport" content="initial-scale=1.0" />
    </head>
    <body>
        <h1>Hello World!</h1>
    </body>
</html>
```

However, it is also possible to include css/js/other content from the same folder as your theme. Therefore, you can include a JavaScript file like so:
```
<html>
    <head>
        <meta name="viewport" content="initial-scale=1.0" />
        <script src="Example.js"></script>
    </head>
    <body>
        <h1>Hello World!</h1>
    </body>
</html>
```

### HTML Theme Javascript Callbacks
Laetus provides some extra useful information to HTML themes via Javascript.
All callbacks are option and do not need to be overridden in your theme.

The callbacks are as follows:
```
laetusKeyPlaneDidChange(state) - Called when the keyboard becomes visible or the keyboards 'KeyPlane' changes. The possible states are: "Letters", "Numbers", "Emoji".

laetusDictationViewWillShow() - Called when the dictation view appears
laetusDictationViewWillHide() - Called when the dictation view disappears

laetusDidTouchDown(x,y) - Called when the user taps on the keyboard. Provides the x,y position relative the view. (e.g. 0,0 for the top left).

laetusCurrentLanguage(language) - Called when the keyboard becomes visible or when the language changes. Language is provided directly from the keyboard APIs and appears to always conform to the ISO language standard (e.g. en_GB). - More information here (https://en.wikipedia.org/wiki/Language_localisation), note that hyphens will be returned as underscores. 
```

An example of overriding one of these methods would look as follows, from the "Example.js" file:
```
function laetusKeyPlaneDidChange(keyplaneName)
{
    console.log("KeyPlane did change to: " + keyplaneName);
}
```

### HTML Theme Format
As with all Laetus themes, the theme should be a folder in ```/Library/Laetus/Themes```.
Files for the theme must be stored in a sub-folder called ```HTML```

This GitHub repository includes an example theme showing the structure and an example HTML theme. However, the structure looks as follows:

![HTML Theme Structure](https://i.imgur.com/HhTYDDX.png)

Themes can then be packaged into a deb file the same way traditional iOS themes are (e.g. for SnowBoard or other theming engines).

## Hybrid Themes
Laetus also supports using a combination of HTML and Images.
To package a theme like this, simply include both ```Images``` and ```HTML``` sub-folders.

## Presets
Presets can be used by both designers and users alike. To create a preset go to Laetus preferences > Presets > And tap the '+' button.
Presets simply are a copy of the Laetus preferences file, so DO NOT include your theme and/or images.
However, these can be useful to provide alongside packaged themes to setup the user preferences in the way you are expecting (e.g. text colour, hide key caps, etc.)

Presets are stored in ```/Library/Laetus/Presets```, and can be packaged as part of your deb file the same way traditional iOS themes are (e.g. for SnowBoard or other theming engines).