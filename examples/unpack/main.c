#include <stdio.h>
#include <inttypes.h>

#include <msgpack.h>

void app_main() {
    const uint8_t data[] = {0xac, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20,
                            0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21};
    msgpack_zone msgpack_pool;
    msgpack_zone_init(&msgpack_pool, 1024);

    msgpack_object unpacked;
    msgpack_unpack((const char *)data, sizeof(data), NULL, &msgpack_pool, &unpacked);
    if (unpacked.type == MSGPACK_OBJECT_STR) {
        printf("unpacked message: ");
        fwrite(unpacked.via.str.ptr, 1, unpacked.via.str.size, stdout);
        printf("\n");
    }
    // msgpack_object_print(stdout, unpacked);

    msgpack_zone_destroy(&msgpack_pool);
}
