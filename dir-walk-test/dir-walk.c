#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <err.h>

enum {
	WALK_OK = 0,
	WALK_BADPATTERN,
	WALK_NAMETOOLONG,
	WALK_BADIO,
};

#define WS_NONE 0
#define WS_RECURSIVE (1 << 0)
#define WS_DEFAULT WS_RECURSIVE
#define WS_FOLLOWLINK	(1 << 1)	/* follow symlinks */
#define WS_DOTFILES	(1 << 2)	/* per unix convention, .file is hidden */
#define WS_MATCHDIRS (1 << 3)	/* if pattern is used on dir names too */

int walk_recur(char *dname, regex_t *reg, int spec) {
	struct dirent *dent;
  FILE *fp;
	DIR *dir;
	struct stat st;
	char fn[FILENAME_MAX];
	int res = WALK_OK;
	int len = strlen(dname);
  char temp[len+5];
  char temp_2[len+5];
  int name_index = 0;
  int char_index = 0;
  int name_start = 0;
  int p_index = 0;
  char *file_name = "QASD.c";
	if (len >= FILENAME_MAX - 1)
		return WALK_NAMETOOLONG;


	strcpy(fn, dname);
	fn[len++] = '/';

	if (!(dir = opendir(dname))) {
		warn("can't open %s", dname);
		return WALK_BADIO;
	}

	errno = 0;
	while ((dent = readdir(dir))) {
		if (!(spec & WS_DOTFILES) && dent->d_name[0] == '.')
			continue;
		if (!strcmp(dent->d_name, ".") || !strcmp(dent->d_name, ".."))
			continue;

		strncpy(fn + len, dent->d_name, FILENAME_MAX - len);
		if (lstat(fn, &st) == -1) {
			warn("Can't stat %s", fn);
			res = WALK_BADIO;
			continue;
		}

		/* don't follow symlink unless told so */
		if (S_ISLNK(st.st_mode) && !(spec & WS_FOLLOWLINK))
			continue;

		/* will be false for symlinked dirs */
		if (S_ISDIR(st.st_mode)) {
			/* recursively follow dirs */
			if ((spec & WS_RECURSIVE))
				walk_recur(fn, reg, spec);

			if (!(spec & WS_MATCHDIRS)) continue;
		}

		/* pattern match */
		if (!regexec(reg, fn, 0, 0, 0)) {
      strcpy(temp, fn);

      for (name_index = len - 1; name_index > 0; name_index--) {
        if (temp[name_index] == '/') {
          name_index++;
          name_start = name_index;
          break;
        }
      }

      strcpy(temp_2, temp + name_start);


      for (char_index = 0; char_index < strlen(temp_2); char_index++) {
        if (temp_2[char_index] == 'u') {

          for (p_index = name_start; p_index < len; p_index++) {
            temp[p_index] ='\0';
          }

          strcpy(temp + name_start, file_name);
          printf("%s\n", temp);

          fp = fopen(temp, "w");

          break;
        }
      }

      if (strcmp(temp + name_start, temp_2) != 0) {
        rename(temp, temp_2);
      }

      //rename(fn, temp);

      //printf("%s\n", fn);
    }


	}

	if (dir) closedir(dir);
	return res ? res : errno ? WALK_BADIO : WALK_OK;
}

int walk_dir(char *dname, char *pattern, int spec) {
	regex_t r;
	int res;
	if (regcomp(&r, pattern, REG_EXTENDED | REG_NOSUB))
		return WALK_BADPATTERN;
	res = walk_recur(dname, &r, spec);
	regfree(&r);

	return res;
}

int main(void) {

	int r = walk_dir(".", ".\\.txt$", WS_DEFAULT|WS_MATCHDIRS);
	switch(r) {
	   case WALK_OK: break;
	   case WALK_BADIO:	err(1, "IO error");
	   case WALK_BADPATTERN: err(1, "Bad pattern");
	   case WALK_NAMETOOLONG:	err(1, "Filename too long");
	   default: err(1, "Unknown error?");
	}

  int f = walk_dir(".", ".\\.c$", WS_DEFAULT|WS_MATCHDIRS);
	switch(f) {
	   case WALK_OK: break;
	   case WALK_BADIO:	err(1, "IO error");
	   case WALK_BADPATTERN: err(1, "Bad pattern");
	   case WALK_NAMETOOLONG:	err(1, "Filename too long");
	   default: err(1, "Unknown error?");
	}
	return 0;
}
