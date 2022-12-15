// CONSOLE
#include <windows.h>
#include <stdp>

#pragma comment( lib, "shell32" )

#include <sddb>

const char *js = "\n<script>\n"
"\n"
"	document.addEventListener(\"DOMContentLoaded\", function(e) {\n"
"		setListners();\n"
"	});\n"
"\n"
"	function setListners() {\n"
"		var vpcs = document.getElementsByClassName(\"chatVideoPlayControl\");\n"
"		var crcs = document.getElementsByClassName(\"BBCodeResizeControl\");\n"
"		\n"
"		for(let i = 0; i < vpcs.length; i++) {\n"
"			vpcs[i].addEventListener(\"click\", vidPlay);\n"
"		}\n"
"		\n"
"		for(let i = 0; i < crcs.length; i++) {\n"
"			crcs[i].addEventListener(\"mousedown\", initDrag, false);\n"
"			console.log(i);\n"
"		}\n"
"	}\n"
"\n"
"	function vidPlay(e) {\n"
"		var vc = e.target;\n"
"\n"
"		while(!vc.classList.contains(\"chatVideoPlayControl\"))\n"
"		{\n"
"			vc = vc.parentNode;\n"
"		}\n"
"		\n"
"		vc.style.display = \"none\";\n"
"		\n"
"		var vid = vc.previousElementSibling;\n"
"\n"
"		vid.play();\n"
"		\n"
"		setTimeout(vctrl, 1000, vid);\n"
"	}\n"
"	\n"
"	function vctrl(element) {\n"
"		element.setAttribute(\"controls\", \"\");\n"
"	}\n"
"	\n"
"	var startX, startY, startWidth, startHeight, rc;\n"
"\n"
"	function initDrag(e) {\n"
"		console.log(\"INITINDRAGGG\");\n"
"		\n"
"		rc = e.target;\n"
"		while(!rc.classList.contains(\"BBCodeResizableComponent\"))\n"
"		{\n"
"			rc = rc.parentNode;\n"
"		}\n"
"\n"
"		startX = e.clientX;\n"
"		startY = e.clientY;\n"
"		startWidth = parseInt(document.defaultView.getComputedStyle(rc).width, 10);\n"
"		startHeight = parseInt(document.defaultView.getComputedStyle(rc).height, 10);\n"
"		document.documentElement.addEventListener(\"mousemove\", doDrag, false);\n"
"		document.documentElement.addEventListener(\"mouseup\", stopDrag, false);\n"
"	}\n"
"\n"
"	function doDrag(e) {\n"
"		var w = (startWidth + e.clientX - startX) + \"px\";\n"
"		rc.style.width = w;\n"
"		rc.style.maxWidth = w;\n"
"	}\n"
"\n"
"	function stopDrag(e) {\n"
"		document.documentElement.removeEventListener(\"mousemove\", doDrag, false);\n"
"		document.documentElement.removeEventListener(\"mouseup\", stopDrag, false);\n"
"	}\n"
"	\n"
"</script>\n"
"<style>\n"
"\n"
"	.chatImageURL, .BBCodeCollapseControl, .emoticon_NewEmoticonIndicator_3O2gR {\n"
"		display: none !important;\n"
"	}\n"
"\n"
"	video {\n"
"		background-image: url(data:image/svg+xml;base64,PHN2ZwogICB2ZXJzaW9uPSIxLjEiCiAgIGlkPSJMYXllcl8xIgogICB4PSIwcHgiCiAgIHk9IjBweCIKICAgdmlld0JveD0iMCAwIDMzMCAzMzAiCiAgIHN0eWxlPSJlbmFibGUtYmFja2dyb3VuZDpuZXcgMCAwIDMzMCAzMzA7IgogICB4bWw6c3BhY2U9InByZXNlcnZlIgogICB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciCiAgIHhtbG5zOnN2Zz0iaHR0cDovL3d3dy53My5vcmcvMj"
	"AwMC9zdmciPjxkZWZzCiAgIGlkPSJkZWZzNDAiIC8+CjxnCiAgIGlkPSJYTUxJRF81MzFfIj4KCTxwYXRoCiAgIGlkPSJYTUxJRF81MzJfIgogICBkPSJNMjU1LDIxMGgtMTBjLTguMjg0LDAtMTUsNi43MTYtMTUsMTVjMCw4LjI4NCw2LjcxNiwxNSwxNSwxNWgxMGM4LjI4NCwwLDE1LTYuNzE2LDE1LTE1ICAgQzI3MCwyMTYuNzE2LDI2My4yODQsMjEwLDI1NSwyMTB6IgogICBzdHlsZT0iZm9udC12YXJpYXRpb24tc2V0dGluZ3M6bm9ybWFsO29wYWNpdHk6MTt2"
	"ZWN0b3ItZWZmZWN0Om5vbmU7ZmlsbDojZTZlNmU2O2ZpbGwtb3BhY2l0eToxO3N0cm9rZS13aWR0aDoxO3N0cm9rZS1saW5lY2FwOmJ1dHQ7c3Ryb2tlLWxpbmVqb2luOm1pdGVyO3N0cm9rZS1taXRlcmxpbWl0OjQ7c3Ryb2tlLWRhc2hhcnJheTpub25lO3N0cm9rZS1kYXNob2Zmc2V0OjA7c3Ryb2tlLW9wYWNpdHk6MTstaW5rc2NhcGUtc3Ryb2tlOm5vbmU7c3RvcC1jb2xvcjojMDAwMDAwO3N0b3Atb3BhY2l0eToxIiAvPgoJPHBhdGgKICAgaWQ9IlhNTElEXz"
	"UzM18iCiAgIGQ9Ik0yODUsMTUwaC00MGMtOC4yODQsMC0xNSw2LjcxNi0xNSwxNWMwLDguMjg0LDYuNzE2LDE1LDE1LDE1aDQwYzguMjg0LDAsMTUtNi43MTYsMTUtMTUgICBDMzAwLDE1Ni43MTYsMjkzLjI4NCwxNTAsMjg1LDE1MHoiCiAgIHN0eWxlPSJmaWxsOiNlNmU2ZTY7Zm9udC12YXJpYXRpb24tc2V0dGluZ3M6bm9ybWFsO29wYWNpdHk6MTt2ZWN0b3ItZWZmZWN0Om5vbmU7ZmlsbC1vcGFjaXR5OjE7c3Ryb2tlLXdpZHRoOjE7c3Ryb2tlLWxpbmVjYXA6"
	"YnV0dDtzdHJva2UtbGluZWpvaW46bWl0ZXI7c3Ryb2tlLW1pdGVybGltaXQ6NDtzdHJva2UtZGFzaGFycmF5Om5vbmU7c3Ryb2tlLWRhc2hvZmZzZXQ6MDtzdHJva2Utb3BhY2l0eToxOy1pbmtzY2FwZS1zdHJva2U6bm9uZTtzdG9wLWNvbG9yOiMwMDAwMDA7c3RvcC1vcGFjaXR5OjEiIC8+Cgk8cGF0aAogICBpZD0iWE1MSURfNTM0XyIKICAgZD0iTTMxNSw5MGgtNzBjLTguMjg0LDAtMTUsNi43MTYtMTUsMTVzNi43MTYsMTUsMTUsMTVoNzBjOC4yODQsMCwxNS"
	"02LjcxNiwxNS0xNVMzMjMuMjg0LDkwLDMxNSw5MHoiCiAgIHN0eWxlPSJmaWxsOiNlNmU2ZTY7Zm9udC12YXJpYXRpb24tc2V0dGluZ3M6bm9ybWFsO29wYWNpdHk6MTt2ZWN0b3ItZWZmZWN0Om5vbmU7ZmlsbC1vcGFjaXR5OjE7c3Ryb2tlLXdpZHRoOjE7c3Ryb2tlLWxpbmVjYXA6YnV0dDtzdHJva2UtbGluZWpvaW46bWl0ZXI7c3Ryb2tlLW1pdGVybGltaXQ6NDtzdHJva2UtZGFzaGFycmF5Om5vbmU7c3Ryb2tlLWRhc2hvZmZzZXQ6MDtzdHJva2Utb3BhY2l0"
	"eToxOy1pbmtzY2FwZS1zdHJva2U6bm9uZTtzdG9wLWNvbG9yOiMwMDAwMDA7c3RvcC1vcGFjaXR5OjEiIC8+Cgk8cGF0aAogICBpZD0iWE1MSURfNTM1XyIKICAgZD0iTTE5Mi4wNzgsMzEuNzc1Yy00Ljg3OC0yLjYxLTEwLjc5Ni0yLjMyNC0xNS4zOTgsMC43NDRMOTAuNDU5LDkwSDE1Yy04LjI4NCwwLTE1LDYuNzE2LTE1LDE1djEyMCAgIGMwLDguMjg0LDYuNzE2LDE1LDE1LDE1aDc1LjQ1OWw4Ni4yMjEsNTcuNDgxYzIuNTEsMS42NzMsNS40MTEsMi41MTksOC"
	"4zMjEsMi41MTljMi40MjcsMCw0Ljg1OS0wLjU4OCw3LjA3Ny0xLjc3NSAgIGM0Ljg3Ny0yLjYxLDcuOTIyLTcuNjkzLDcuOTIyLTEzLjIyNVY0NUMyMDAsMzkuNDY4LDE5Ni45NTUsMzQuMzg1LDE5Mi4wNzgsMzEuNzc1eiBNMTcwLDI1Ni45NzJsLTY2LjY4LTQ0LjQ1MyAgIEMxMDAuODU2LDIxMC44NzYsOTcuOTYxLDIxMCw5NSwyMTBIMzB2LTkwaDY1YzIuOTYxLDAsNS44NTYtMC44NzYsOC4zMi0yLjUxOUwxNzAsNzMuMDI4VjI1Ni45NzJ6IgogICBzdHlsZT0i"
	"ZmlsbDojZTZlNmU2O2ZpbGwtb3BhY2l0eToxIiAvPgo8L2c+CjxnCiAgIGlkPSJnNyI+CjwvZz4KPGcKICAgaWQ9Imc5Ij4KPC9nPgo8ZwogICBpZD0iZzExIj4KPC9nPgo8ZwogICBpZD0iZzEzIj4KPC9nPgo8ZwogICBpZD0iZzE1Ij4KPC9nPgo8ZwogICBpZD0iZzE3Ij4KPC9nPgo8ZwogICBpZD0iZzE5Ij4KPC9nPgo8ZwogICBpZD0iZzIxIj4KPC9nPgo8ZwogICBpZD0iZzIzIj4KPC9nPgo8ZwogICBpZD0iZzI1Ij4KPC9nPgo8ZwogICBpZD0iZzI3Ij4KPC"
	"9nPgo8ZwogICBpZD0iZzI5Ij4KPC9nPgo8ZwogICBpZD0iZzMxIj4KPC9nPgo8ZwogICBpZD0iZzMzIj4KPC9nPgo8ZwogICBpZD0iZzM1Ij4KPC9nPgo8L3N2Zz4=);\n"
"		background-repeat: no-repeat;\n"
"		background-position: center center;\n"
"		background-size: 32px auto;\n"
"	}\n"
"\n"
"</style>";

int wmain(int argc, wchar_t **argv)
{	
	if(argc < 2)
	{
		return 1;
	}
	
	wtxt htm_path = argv[1];
	
	wtxt ext = txts(htm_path, '.' << htm_path, TEND);
	if(ext != L".htm" && ext != L".html")
	{
		return 1;
	}
	
	wtxt htm_root = txts(htm_path, 0, ('\\' << htm_path) + 1);
	wtxt htm_files = htm_path;
	txtr(htm_files, ~htm_files-4, 4, L"_files\\");
	
	// Create or open File or Device =================================================================
	HANDLE f = CreateFile(
		htm_path,					    //   [I]  Name of the file or device to create/open
		GENERIC_READ,   				//   [I]  Requested access GENERIC_READ|GENERIC_WRITE|0
		FILE_SHARE_READ,			    //   [I]  Sharing mode FILE_SHARE_READ|WRITE|DELETE|0
		NULL,						    // [I|O]  SECURITY_ATTRIBUTES for file, handle inheritability
		OPEN_EXISTING,				    //   [I]  Action to take if file/device exist or not
		FILE_FLAG_SEQUENTIAL_SCAN,	    //   [I]  Attributes and flags for file/device
		NULL);						    // [I|O]  Handle to template file to copy attributes from
	// ===============================================================================================
	
	if(f == INVALID_HANDLE_VALUE)
	{
		return 2;
	}
	
	DWORD br;
	char buff[1025];
	txt site;
	while(ReadFile(f, &buff, 1024, &br, NULL) && br)
	{
		buff[br] = 0;
		site += buff;
	}
	
	CloseHandle(f);
	
	p|"Fixing YouTube iframes... Note: some videos might refuse to be shown in offline iframe anyway"|N;	
	txt yt_comp = "BBCodeYouTubeComponent";
	txt lnk_cont = "data-copytext="; // Link Container
	txt yt_vid = "https://www.youtube.com/watch\?v=";
	txt yt_t = "&amp;t="; // OR '"'
	
	txt iframe = "<iframe";
	txt isrc = "src=\"";
	
	ui64 pos = 0;
	
	while(1)
	{
		pos = txtf(site, pos, yt_comp);
		
		if(pos == NFND)
		{
			break;
		}
		else
		{
			pos += ~yt_comp;
		}
		
		pos = txtf(site, pos, lnk_cont) + ~lnk_cont;
		pos = txtf(site, pos, yt_vid) + ~yt_vid;
		
		ui64 tmpp = pos;
		while(site[tmpp] != '&' && site[tmpp] != '"')
		{
			++tmpp;
		}
		
		txt url = txtsp(site, pos, tmpp-1);
		pos = tmpp;
		
		txt t_descr = txts(site, pos, ~yt_t);
		txt time;
		if(t_descr == yt_t)
		{
			pos += ~yt_t;
			while(site[pos] != 's' && site[pos] != '"')
			{
				time += site[pos];
				++pos;
			}
		}
		else
		{
			time += '0';
		}
		
		pos = txtf(site, pos, iframe) + ~iframe;
		pos = txtf(site, pos, isrc) + ~isrc;
		
		tmpp = txtf(site, pos, '"') - 1;
		txt lif = txtsp(site, pos, tmpp);
		DeleteFile(htm_root + t2u16(lif)); // Remove useless offline youtube iframe files
		
		wtxt lif_dat = htm_files + t2u16(url) + L"_data"; // And also remove possible data folders of this files
		SHFILEOPSTRUCT shfo;
		memset(&shfo, 0x0, sizeof(SHFILEOPSTRUCT));
		shfo.wFunc = FO_DELETE;
		shfo.pFrom = lif_dat += '\0';
		shfo.fFlags = FOF_NO_UI;
		
		SHFileOperation(&shfo);
		
		txt iurl = "https://www.youtube.com/embed/" + url +
			"?autoplay=0&amp;showinfo=0&amp;autohide=1&amp;fs=1&amp;modestbranding=1&amp;rel=0&amp;"
			"playsinline=0&amp;iv_load_policy=3&amp;controls=1&amp;start=" + time;
		
		txtr(site, pos, ~lif, iurl);
		pos += ~iurl;
	}
	
	p|"Ensuring short videos will play instantly in Firefox by preloading them..."|N;
	txt vid_tag = "<video";
	txt vpre_load = " preload=\"auto\"";
	pos = 0;
	
	while(1)
	{
		pos = txtf(site, pos, vid_tag);
		
		if(pos == NFND)
		{
			break;
		}
		else
		{
			pos += ~vid_tag;
		}
		
		txti(site, pos, vpre_load);
		pos += ~vpre_load;
	}
	
	p|"Removing all javascript files..."|N;
	WIN32_FIND_DATA fd;
	HANDLE fdh = FindFirstFile(htm_files + '*', &fd);
	if(fdh != INVALID_HANDLE_VALUE)
	{
		wtxt fn;
		do
		{
			fn = fd.cFileName;
			if(~fn < 4)
			{
				continue;
			}
			
			wtxt fe = txts(fn, ~fn-3, 3);
			
			if(fe == L".js" || fe == L".JS")
			{
				DeleteFile(htm_files + fn);
			}
		}
		while(FindNextFile(fdh, &fd));
	}
	FindClose(fdh);
	
	p|"Injecting custom javascript..."|N;
	txt head = "<head>";
	pos = 0;
	pos = txtf(site, pos, head) + ~head;
	txti(site, pos, js);
	
	CloseHandle(f);
	
	
	p|"Overwriting html file..."|N;
	// Create or open File or Device =================================================================
	f = CreateFile(
		htm_path,					  //   [I]  Name of the file or device to create/open
		GENERIC_WRITE, 				  //   [I]  Requested access GENERIC_READ|GENERIC_WRITE|0
		FILE_SHARE_READ,			  //   [I]  Sharing mode FILE_SHARE_READ|WRITE|DELETE|0
		NULL,						  // [I|O]  SECURITY_ATTRIBUTES for file, handle inheritability
		CREATE_ALWAYS,			 	  //   [I]  Action to take if file/device exist or not
		FILE_FLAG_SEQUENTIAL_SCAN,	  //   [I]  Attributes and flags for file/device
		NULL);						  // [I|O]  Handle to template file to copy attributes from
	// ===============================================================================================
	
	WriteFile(f, site, (DWORD)~site, &br, NULL);
	CloseHandle(f);
	
	p|"Profit!!!"|N;
	p|TB|P;
	return 0;
}