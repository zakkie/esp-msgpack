Import('env')

global_env = DefaultEnvironment()
global_env.Append(
    CPPDEFINES=[
        "MSGPACK_ENDIAN_LITTLE_BYTE",
    ]
)
