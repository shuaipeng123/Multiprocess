import math
class Point(object):
	def __init__(self,x,y):
		self.x=float(x)
		self.y=float(y)
	def __str__ (self):
		return '(' +str(self.x) +','+str(self.y)+')'
	
class Line(object):
	def __init__ (self,src,dst):
		self.src=src
		self.dst=dst
	def __str__(self):
		return str(self.src)+'-->'+str(self.dst)
		
def distance1(a,b):
	return math.sqrt((float(a.x)*1.0-float(b.x)*1.0)**2+(float(a.y)*1.0-float(b.y)*1.0)**2)
def is_between1(a,c,b):
	return distance1(a,c)+distance1(c,b)-distance1(a,b)<0.00001	
	
def intersect(l1,l2):
	x1,y1=float(l1.src.x)*1.0,float(l1.src.y)*1.0
	x2,y2=float(l1.dst.x)*1.0,float(l1.dst.y)*1.0
	x3,y3=float(l2.src.x)*1.0,float(l2.src.y)*1.0
	x4,y4=float(l2.dst.x)*1.0,float(l2.dst.y)*1.0
	if((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)==0):
		midp1_x=(x1+x2)/2
		midp1_y=(y1+y2)/2
		midp2_x=(x3+x4)/2
		midp2_y=(y3+y4)/2
		arr=[(l1.src.x,l1.src.y),(l1.dst.x,l1.dst.y),(l2.src.x,l2.src.y),(l2.dst.x,l2.dst.y)]
		arr1=sorted(arr,key=lambda tup:tup[0])
		arr2=sorted(arr1,key=lambda tup:tup[1])
		if(distance1(Point(midp1_x,midp1_y),Point(midp2_x,midp2_y))>(0.5)*distance1(Point(arr2[0][0],arr2[0][1]),Point(arr2[3][0],arr2[3][1]))):
			return 0
		else:
			points=[]
			p1=Point(arr2[1][0],arr2[1][1])
			p2=Point(arr2[2][0],arr2[2][1])
			if(is_between1(l2.src,p1,l2.dst) and is_between1(l1.src,p1,l1.dst)):
				points.append(p1)
			
			if(is_between1(l2.src,p2,l2.dst) and is_between1(l1.src,p2,l1.dst)):
				points.append(p2)
			return points
	else:
		xcoor=((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4))
		ycoor=((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4))
		if(is_between1(l2.src,Point(xcoor,ycoor),l2.dst) and is_between1(l1.src,Point(xcoor,ycoor),l1.dst)):
			return Point(xcoor, ycoor)
		else:
			return 0