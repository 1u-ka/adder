#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

#include "fs.c"
#include "io.c"

json_object *
add(int num, char *key, json_object *o) {

  json_object *tgt = json_object_object_get(o, key);

  if (!tgt) {
    json_object_object_add(o, key, json_object_new_int(0));
    tgt = json_object_object_get(o, key);
  }

  json_object_int_inc(tgt, num);
  return o;
}

int
main(int argc, char *argv[]) {
  char *fp              = fs_touch(fs_path("adder"));
  struct json_object *o = json_object_from_file(fp);

  char *ctx = "primary";
  int amt   = 0;

  if (1 < argc) {
    amt = io_parseamt(argc, argv);
    ctx = io_parsectx(argc, argv, ctx);
  }

  if (0 < amt) {
    o = add(amt, ctx, o);
    json_object_to_file(fp, o);
  }

  puts(json_object_to_json_string_ext(o, JSON_C_TO_STRING_PRETTY));

  json_object_put(o);
  free(fp);

  return 0;
}
