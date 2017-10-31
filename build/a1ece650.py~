import sys
import re
import math
import string
import random
from ag_intersect import *
dict={}
vertex={}
edge=[]
intersect_points=[]
count=0
line_segment=[]
line_segment_ver=[]
position_delete=[]
#points=[]
class ParseException(Exception):
    def __init__(self, value):
        self._value = value

    def __str__(self):
        return str(self._value)
#this function save all points to points[] list
def checkIfpointIsIntersection(p):
	for v in intersect_points:
		if(p.x==v.x and p.y==v.y):
			return True
	return False
def get_point_position(p):
	for k,v in vertex.items():
		if(p.x==v.x and p.y==v.y):
			return k
	return 0
def transform_line_to_vertex_res():
	for l in line_segment:
		if(l!=0):
			n=get_point_position(l.src)
			m=get_point_position(l.dst)
			line_segment_ver.append((n,m))		
	
def checkIflineInLinesegments(l1):
	flag=True
	for l in line_segment:
		if(l!=0):
			if(l.src.x==l1.src.x and l.src.y==l1.src.y and l.dst.x==l1.dst.x and l.dst.y==l1.dst.y):
				flag=False
	if flag:
		line_segment.append(l1)
def distance(a,b):
	return math.sqrt((float(a.x)*1.0-float(b.x)*1.0)**2+(float(a.y)*1.0-float(b.y)*1.0)**2)
def is_between(a,c,b):
	if(distance(a,c)==0 or distance(c,b)==0):
		return False
	return abs(distance(a,c)+distance(c,b)-distance(a,b))<0.00001
def listTopoint (mylist):
	points=[]
	for index in range(len(mylist)):
		point=mylist[index].strip()
		point=point.replace("(","")
		point=point.replace(")","")
		p=point.split(",")	
		points.append(Point(p[0],p[1]))
	return points
def savePoints(p):
	flag=True
	for k,v in vertex.items():	
		if(v.x==p.x and v.y==p.y):
			flag=False
	if flag:
		global count
		count=count+1
		if re.match("^[a-zA-Z0-9]*$", str(count)):
			vertex[count]=p
def savelines(l1,l2):
	savePoints(l1.src)
	savePoints(l1.dst)
	savePoints(l2.src)
	savePoints(l2.dst)

def run(input, out, err):
	while True:
		line=input.readline()
		if line=='\n':
			break
		try:    
                        print line
			string_a=re.compile("^\s*a\s+[\"].*[\"]\s+(\(\s*-?\d+,\s*-?\d+\)\s*)*$")
			string_point=re.compile("(\(\s*-?\d+,\s*-?\d+\))") #this is for points, need to use re.compile first
			string_street=re.compile("\".+\"")
			string_s=re.findall(string_street,line)
			string_s1=[]
			for x in range(len(string_s)):
				string_s1.append(string_s[x].lower())				
			if(string_s1!=[]):
				if not re.match("^\"[a-zA-Z ]*\"$", str(string_s1[0])):
					raise ParseException("Street name can only contains letters")
			string_c=re.compile("^\s*c\s+[\"].*[\"]\s+(\(\s*-?\d+,\s*-?\d+\)\s*)*$")
			string_r=re.compile("^\s*r\s+[\"].*[\"]\s*$")
			string_g=re.compile("^\s*g\s*$")
			string_p=re.findall(string_point,line)
			if re.findall(string_a,line)!=[]:
				if(string_s1==[]):
					raise ParseException("It doesn't contain a street")
				if(string_p==[]):
					raise ParseException("It doesn't have any points")
				if(len(string_p)<2):
					raise ParseException("It can not have one point line segment")
				points=listTopoint(string_p)
				if(string_s1[0] in dict.keys()):
					raise ParseException("It have this street")
				dict[string_s1[0]]=points
			elif re.findall(string_c,line)!=[]:
				if(string_s1==[]):
					raise ParseException("It doesn't contain a street")
				if(string_p==[]):
					raise ParseException("It doesn't have any points")
				if(len(string_p)<2):
					raise ParseException("It can not have one point line segment")
				points=listTopoint(string_p)
				if(string_s1[0] not in dict.keys()):
					raise ParseException("It doesn't have this street")
				dict[string_s1[0]]=points
			elif re.findall(string_r,line)!=[]:
				if(string_s1==[]):
					raise ParseException("It doesn't contain a street")
				if(string_s1[0] not in dict.keys()):
					raise ParseException("It doesn't have this street")
				del dict[string_s1[0]]
			elif re.findall(string_g,line)!=[]:
				for i in range(len(dict)):
					k,v=dict.items()[i]   #this k, v is the initial k,v, v means values which means points
					for j in range(len(v)-1): #this is to get the point in points list
						line1=Line(v[j],v[j+1])   #this is to build the line for every two point
						for index in range(i+1,len(dict)):     #this rest is loop every other line segment
							k1,v1=dict.items()[index]
							for x in range(len(v1)-1):
								line2=Line(v1[x],v1[x+1])
								checkIflineInLinesegments(line1)
								checkIflineInLinesegments(line2)
								if intersect(line1,line2)!=0 and not isinstance(intersect(line1,line2),list):
									intersect_p=intersect(line1,line2)
									savelines(line1,line2)
									savePoints(intersect_p)
									flag=True
									for p in intersect_points:
										if(intersect_p.x==p.x and intersect_p.y==p.y):
											flag=False
									if flag:
										intersect_points.append(intersect_p)
								elif isinstance(intersect(line1,line2),list):
									intersection=intersect(line1,line2)
									if intersection!=[]:
										savelines(line1,line2)
										for inter in intersection:
											savePoints(inter)
											intersect_points.append(inter)
				for p in intersect_points:
					for position in range(len(line_segment)):
						if(line_segment[position]!=0):
							if(is_between(line_segment[position].src,p,line_segment[position].dst)):
								checkIflineInLinesegments(Line(line_segment[position].src,p))
								checkIflineInLinesegments(Line(p,line_segment[position].dst))	
								line_segment[position]=0
				for position in range(len(line_segment)):
					if(line_segment[position]!=0):
						if not (checkIfpointIsIntersection(line_segment[position].src) or checkIfpointIsIntersection(line_segment[position].dst)):
							line_segment[position]=0
				transform_line_to_vertex_res()
				out.write("V={\n")
				for  k,v in vertex.items():
					out.write("{0}:  ({1:.2f}, {2:.2f})\n".format(k,v.x,v.y))
				out.write("}\n")
				out.write("E={\n")
				for  l in line_segment_ver:
					if(l[0]!=0 and l[1]!=0):
						out.write("  <{0},{1}>\n".format(l[0],l[1]))
				out.write("}\n")
				del line_segment[:]
				del line_segment_ver[:]
				vertex.clear()
				global count
				count=0
				del intersect_points[:]
			else:
				if (not line.startswith('a')) and (not line.startswith('c')) and (not line.startswith('r')) and (not line.startswith('g')):
					raise ParseException("It doesn't start with a,c,g and r")
				string_single_quote=re.compile("\'.*\'")
				string_sq=re.findall(string_single_quote,line)
				if string_sq!=[]:
					raise ParseException("Single quotation is not accepted")
				if string_p==[] and (not line.startswith('g')):
					raise ParseException("Missing bracket")
				raise ParseException("Format is wrong")
		except Exception as ex:
			 err.write("Error: {0}\n".format(ex))
	sys.exit(0)
def main():
	
	run(sys.stdin,sys.stdout,sys.stderr)
if __name__=='__main__':
	main()
	import numpy as np
	import pylab as pl
	from matplotlib import collections as mc
	lines = [[(-1,6),(7,-2),(5,-5),(5,-7)], [(-1,5),(5,5)], [(0,0),(7,7)],[(5,0),(5,7),(7,7),(9,9)],[(3,-2),(3,7)]]
	c = np.array([(1, 0, 1, 1), (0, 1, 0, 1), (0, 0, 1, 1),(1, 0, 0, 1),(1, 1, 1, 1)])
	lc = mc.LineCollection(lines, colors=c, linewidths=2)

	fig, ax = pl.subplots()
	ax.add_collection(lc)

	ax.autoscale()
	ax.margins(0.1)
	'''
	for key,value in vertex.items():
		pl.plot(value.x,value.y,'ro',label="point")
	for l in line_segment:
		if(l!=0):
			pl.plot([l.src.x,l.dst.x],[l.src.y,l.dst.y],"r--")
	'''
	#pl.show()
