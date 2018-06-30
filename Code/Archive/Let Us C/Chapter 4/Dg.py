x = raw_input("please enter the RGB values (space-seperated):")
x_arr = x.split(" ")

for val in x_arr:
	index = x_arr.index(val)
	x_arr[index] = float(val)/255

w = max(x_arr)

if w != 0:
	c = (w - x_arr[0])/255
	m = (w - x_arr[1])/255
	y = (w - x_arr[2])/255
	k = 1 - w
else:
	c = m = y = 0
	k = 1

print("Corresponding CMYK values: C:%f M:%f Y:%f K:%f" % (c,m,y,k))
