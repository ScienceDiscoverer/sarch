# Steam Chat Offline Archiver

This little tool will help you safely back up your favourite Steam chats with your friends.
As you can see from the source code, this tool is 100% local, it does not use any network calls or require login to your account, so you data privacy will not be affected.

All you have to do is follow this steps:

1. Open your Steam chat in your favourite browser (preferably Firefox, but should also work with chromium based ones, I guess)
2. Scroll your chat as far up as Steam lets you (it seems to be hardcoded to about 850 messages)
3. Go into browser menu and press `Save page as...` (or press Ctrl+S)
4. Save as "HTML page, full"
5. At this point, you might try to open the local file. But you will be quickly disappointed. Steam Throbber will forever block your chat while trying to connect to servers. You can remove all .js files to make it go away, but, all the chat functions will be broken. You can't play videos, watch YouTube videos, resize stuff, etc. My program fixes all this problems instantly (although this took ages to implement =(
6. Just drag-n-drop your `.htm` or `.html` file onto the `sarch.exe` and your done! The chat archive will be fixed (alternatively, you can pass full path to the `.htm` or `.html` file via command line or shortcut)

Note: your data folder must be named exactly the same as `.htm/.html` file with `_files` in the end (i.e. `Foo_Bar6934.htm`  --->  `Foo_Bar6934_files`)

What it does?

- Fixes YouTube links to be playable in their `<iframes>` inside the chat and deletes useless files/folders for "offline" iframes
- Fixes short videos not beginning to play instantly
- Removes all JavaScript files from the data folder
- Injects custom JavaScript and styles directly into the `.htm/.html` file that fixes many of the issues and makes the chat as usable as in the online version
