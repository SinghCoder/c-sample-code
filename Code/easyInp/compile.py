import subprocess
import argparse

TO_COMPILE = ["sampleUsage.c", "easyinp.c"]

argparser = argparse.ArgumentParser()
argparser.add_argument("-o", help="Choose the name of the output function.")
args = argparser.parse_args()
command = ["gcc"]
for file in TO_COMPILE:
    command.append(file)
if args.o:
    command.append("-o")
    command.append(args.o)
    subprocess.call(command)
else:
    subprocess.call(command)
