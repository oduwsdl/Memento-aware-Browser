
# Memento-aware Browser
A [Chromium](https://www.chromium.org/Home) based Memento-aware web Browser.

## Features

Videos demonstrating some of the features
* Memento detection: <https://youtu.be/R8Hb3ATRwgk> (0:53)
* Bookmark as archive: <https://youtu.be/qGSyaXJe2jQ> (0:48)
* More examples of memento detection: <https://youtu.be/s_xuSd6Qs98> (4:55)

### Alert the user of archived webpages

The browser detects when a page returns the Memento-Datetime header and alerts the user by adding a Memento icon next to the HTTPS lock icon. The user may click the Memento icon to view the date the page was archived.

![](docs/GIFs/memento-popup.gif?raw=true)

### Alert the user of mixed live web and archived content

There are two scenarios where live web and archived content are mixed within the same page:

  * The page is a Memento with the live web leaking in.
  * The webpage is live and not a Memento, yet it is displaying archived content, such as with iframes that display Mementos on the live webpage.
  
The browser detects both of these instances and alerts the user that there is a mix of live web content and archived content.

![](docs/GIFs/mixed-archival-content.gif?raw=true)

### Alert the user of archived webpages that display live content

The browser detects when an archived page is displaying a frame that is not archived.

![](docs/images/memento-plus-live-content.png?raw=true)

### Bookmark as archive

When the user clicks the star icon to bookmark a page, the browser presents an edit bookmark popup that includes an archive drop down. The user can select an archive from this drop down and the browser will start a background process that utilizes [Archive Now](https://github.com/oduwsdl/archivenow) to archive the bookmarked page.

![](docs/images/bookmark-as-archive.png?raw=true)

## Build and Run
Build instructions for the Memento-aware Browser differ slightly from the [Chromium build instructions](https://www.chromium.org/developers/how-tos/get-the-code).
Chromium uses a package of scripts called [depot_tools](https://dev.chromium.org/developers/how-tos/depottools). To build and run the Memento-aware Browser, you must [install depot_tools](https://commondatastorage.googleapis.com/chrome-infra-docs/flat/depot_tools/docs/html/depot_tools_tutorial.html#_setting_up).
After installing depot_tools, you can clone the repository and change into the src directory.
```
$ git config http.postBuffer 524288000
$ git clone https://github.com/oduwsdl/Memento-aware-Browser.git
$ cd Memento-aware-Browser/src
```

### Installing Archive Now

The Memento-aware Browser uses [Archive Now](https://github.com/oduwsdl/archivenow) for the bookmark as archive feature. In order to use this feature, Archive Now and its dependencies must be installed.

### Linux
After you have installed depot_tools and cloned the repository, assuming you are using Ubuntu, run [install-build-deps.sh](https://chromium.googlesource.com/chromium/src/+/master/build/install-build-deps.sh).
```
$ ./build/install-build-deps.sh
```
Now you can run the Chromium specific hooks, which will then download additional binaries.
```
$ gclient runhooks
```
Now create the build directory by running:
```
$ gn gen out/Default
```
* Ninja updates build files as needed, so you only have to run this once for each new build directory.
* You can replace Default with another name.

Finally, you can build Chromium (the "chrome" target) with Ninja using the command:
```
$ autoninja -C out/Default chrome
```
Once built, run the browser with the following command:
```
$ out/Default/chrome
```
### Windows
After you have installed depot_tools and cloned the repository, you can generate the build directory.
```
$ gn gen out/Default
```
Now you can build Chromium (the "chrome" target) with Ninja using the command:
```
$ autoninja -C out/Default chrome
```
Once built, run the browser with the following command:
```
$ out/Default/chrome
```
### Mac (Not tested)
Create the build directory by running:
```
$ gn gen out/Default
```
* Ninja updates build files as needed, so you only have to run this once for each new build directory.
* You can replace Default with another name.

You can then build Chromium (the "chrome" target) with Ninja using the command:
```
$ autoninja -C out/Default chrome
```
Finally, run the browser:
```
$ out/Default/Chromium.app/Contents/MacOS/Chromium
```

## Reference

Please use the following reference for this work:

Abigail Mabe, Michael L. Nelson, and Michele C. Weigle, "Extending Chromium: Memento-aware Browser," In *Proceedings of ACM/IEEE Joint Conference on Digital Libraries (JCDL)*. September 2021, poster.  

(extended version available at https://arxiv.org/abs/2104.13361)
