# Red Eye Project

**Pre-built project binaries for Windows**

Zip File: https://drive.google.com/open?id=0B2cXFE6Ox3lwYTNPV3BMcmNVOG8  
Installer: https://drive.google.com/open?id=0B2cXFE6Ox3lwRXF6T0FYVm43QWs

**Dependent Library Binaries**

https://drive.google.com/open?id=0B2cXFE6Ox3lwNU1DZV9Qdi13SDg

**Required Software for Compiling**

-	Visual Studio 2015 (Any edition) + Windows SDK 14393 + C++ Language
-	Visual Studio 2015 Installer Projects Plugin:
https://marketplace.visualstudio.com/items?itemName=VisualStudioProductTeam.MicrosoftVisualStudio2015InstallerProjects

**Required Hardware**

-	A 64-bit processor (Must be using s 64 bit build of Windows)
-	A video card supporting OpenGL 3.1 or higher (preferably NVidia)
-	2 or more monitors is highly recommended (1 is acceptable)

**Build Instructions**

-	Install the Required Software
-	Update your graphics drivers
-	Pull / Clone the github repository
-	Copy the contents of the library binaries zip file into:
[repository root]\redeyeproject\
-	Open the SLN file:
[repository root]\redeyeproject.sln
-	Select “Debug or Release” build.
-	Build the Solution

**If you want to build an installable version of the build**

-	Select “Release” Build
-	Build the Solution
-	Right-click the project "RedEyeSetup" and select "Build"
-	Copy the MSI file from:
[repository root]\RedEyeSetup\Release\RedEyeSetup.msi 

**If you want the binaries to simply copy or zip**

-	Select “Release” Build
-	Build the Solution
-	Copy all available "fs","vs","dll","exe" files from this directory:
[repository root]\x64\Release\
