# lookUpPostalCode

Zip / Postal Code Lookup – Enter a zip or postal code and have it return which city/cities that are in that zip code.

- for this project, i used curl to download data from the web.

How to install Curl with visual studio 2015
1. Open VIsual Studio Command Prompt (Developer Command Prompt)

2. cd /d D:\bcs\curl-7.45.0\winbuild

3. nmake /f Makefile.vc mode=dll

4. This will create "builds" folder in "curl-7.45.0"

5. rename "libcurl-vc-x86-release-dll-ipv6-sspi-winssl" -> "Release"

6. Open your project and open your project's properties.

7. Navigate to VC++ Directories > Include directories and add C:\curl-7.42.1\builds\release\include

8. Add C:\curl-7.42.1\builds\release\lib to VC++ Directories > Library directories.

9. Go to Linker > Input > Additional Dependencies and add libcurl.lib.

10. Finally copy C:\curl-7.42.1\builds\release\bin\libcurl.dll to your project folder.
(project folder is
C:\Users\aa\Documents\Visual Studio 2015\Projects\(project name)\(project name)
