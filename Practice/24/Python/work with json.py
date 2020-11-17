import json
import os
abspath = os.path.abspath(__file__)
dirname = os.path.dirname(abspath)
os.chdir(dirname)

with open("in.json", "r") as read_file:
    indata = json.load(read_file)
uc = int(0)
for i in range(len(indata)):
    if indata[i]["userId"] >= uc:
        uc = indata[i]["userId"]

outdata = []
for i in range(uc+1):
    completed = 0
    for j in range(len(indata)):
        if (indata[j]["completed"] and indata[j]["userId"] == i):
            completed += 1

    if (completed > 0):
        one_object = {"task_completed":completed, "userId":i}
        outdata += [one_object]
with open("out.json", "w") as write_file:
    json.dump(outdata, write_file, indent=2)