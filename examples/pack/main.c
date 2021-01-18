#include <stdio.h>

#include <msgpack.h>

void app_main() {
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);

    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    msgpack_pack_map(&pk, 2);

    msgpack_pack_str_with_body(&pk, "message", 7);
    msgpack_pack_str_with_body(&pk, "Hello World!", 12);

    msgpack_pack_str_with_body(&pk, "from", 4);
    msgpack_pack_str_with_body(&pk, "PlatformIO", 10);

    printf("Run the following command on your PC:\n");
    printf("python3 -c \"import msgpack; print(msgpack.unpackb(b'");
    for (int i = 0; i< sbuf.size; i++) {
        printf("\\x%x", sbuf.data[i]);
    }
    printf("'))\"\n");
    // output: {'message': 'Hello World!', 'from': 'PlatformIO'}

    msgpack_sbuffer_destroy(&sbuf);
}