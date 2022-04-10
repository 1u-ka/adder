/** */
char *
fs_path(char *fn) {
  char *path = malloc(sizeof(char) * 150);

  sprintf(path, "%s/.%s.json", getenv("HOME"), fn);
  return path;
}

/** */
char * 
fs_touch(char *fp) {
  FILE *f;

  if (NULL == (f = fopen(fp, "r"))) {
    f = fopen(fp, "w+");
    fputs("{}", f);
  }

  fclose(f);

  return fp;
}
