#python
import sys
sys.path.append('/home/mrrobot/Desktop/blog')  # This is an absolute path
import blog 
import os
def solve(file="trip.jpeg"):
  blog.solveup("exiftool linux",file)
if __name__ == "__main__" :
  solve("trip.jpeg")