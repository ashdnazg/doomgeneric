import ctypes
import omg

w = omg.WAD("doom1.wad")

new_maps = {}
for k,v in w.maps.items():
    new_maps[k] = omg.MapEditor(v)

for k,v in new_maps.items():
    w.maps[k] = v.to_lumps()

w.to_file("doom.wad")
