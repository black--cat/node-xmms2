{
  "targets": [
    {
      "target_name": "xmms2",
      "include_dirs": [
        "<!@(pkg-config xmms2-client-cpp --cflags-only-I | sed s/-I//g)",
        "<!@(pkg-config glib-2.0 --cflags-only-I | sed s/-I//g)"
      ],
      "libraries": [
        "<!@(pkg-config xmms2-client-cpp --libs)",
        "<!@(pkg-config glib-2.0 --libs)"
      ],
      "sources": [
        "src/xmms2.cc",
        "src/xmmsclient++/client.cc"
      ]
    }
  ],
  "cflags": [ "-W", "-Wall", "-O3" ]
}
