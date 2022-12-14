# DE To TGF Converter
## What it does
This utility converts graphs from a DF format to a TGF Format. Its original intention is to allow the edition of graphs on different platforms, mobile and desktop.
It uses a [JSON library for C++](https://github.com/nlohmann/json) by Niels Lohmann.
## DF Format
The DF format is a [DrawExpress](https://drawexpress.com/) file encoded in JSON. This file is produced by the DrawExpress APP for [Android](https://play.google.com/store/apps/details?id=com.drawexpress.lite&hl=en&gl=US) or [Apple](https://apps.apple.com/us/app/drawexpress-diagram/id687490743), and contains a graph with nodes and links, but also text, colors, and many details and extras.
## TGF Format
The [Trivial Graph Format](https://en.wikipedia.org/wiki/Trivial_Graph_Format) (TGF) is an open file format that contains information about nodes and the links to those nodes.

It is a simple format with just that information and nothing else.

This format can be opened with [yEd Graph Editor](https://www.yworks.com/). yEd can order the diagram and display different layouts such as:

* Hierarchic
* Organic
* Orthogonal
* Circular
* Tree
* Etc...

## Credits
### JSON Library for C++ by Niels Lohmann 
This little utility was produced thanks to the JSON parsing library for C++ developed by Niels Lohmann and many other contributors under the MIT License.
* [This](https://github.com/nlohmann/json) is the github project link.
* [This](https://nlohmann.me/) is Niels' site.
* [Here](https://json.nlohmann.me/) you can find the documentation.