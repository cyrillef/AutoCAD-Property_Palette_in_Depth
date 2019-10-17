AutoCAD Property Palette in Depth
=================================



![](https://img.shields.io/badge/build-passed-blue)![](https://img.shields.io/badge/ObjectARX-2020-blue)![](https://img.shields.io/badge/AutoCAD-2020-brightgreen)![](https://img.shields.io/badge/platform-windows-lightgrey)![](https://img.shields.io/badge/MIT-License-green)

## Dependencies

- Visual Studio 2017
- ObjectARX and AutoCAD 2020
## Setup
```
•	launch developer command prompt in adminstrator mode(This is require to self register COM )
• 	git clone https://github.com/ADN-DevTech/AutoCAD-Property_Palette_in_Depth.git
•	cd /d AutoCAD-Property_Palette_in_Depth\Sample
•	edit "DeepPropInspector\DeepPropInspector.vcxproj"
•	find D:\Work\ObjectARX2020 and replace with your SDK
•	save *.vcxproj
•	edit "DeepPropInspectorUI\DeepPropInspectorUI.vcxproj"
•	find D:\Work\ObjectARX2020 and replace with your SDK
•	save *.vcxproj
•	msbuild DeepPropInspector.sln /t:Build /p:Configuration=Debug2020;Platform=x64
•	appload x64\Debug2020\DeepPropInspector.dbx
•	appload x64\Debug2020\DeepPropInspectorUI.arx

```

Presentation and Sample from AU on The AutoCAD Property Palette

Written by Cyrille Fauvel, Autodesk Developer Network (ADN)
http://www.autodesk.com/joinadn
May 2004