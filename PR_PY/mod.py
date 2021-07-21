class coord(object):
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def __repr__(self):
        return('Coordinate Object at: {0},{1}'.format(self.x,self.y))
    def __str__(self):
        return("Coordinates %d,%d"%(self.x,self.y))
    def distance(self,param=None):
        '''Leave param blank for dist from center'''
        import math
        if param is None:return(math.sqrt( (self.x-0)**2 + (self.y-0)**2 ))
        return(math.sqrt( (self.x-param.x)**2 + (self.y-param.y)**2 ))
    @staticmethod
    def name():
    	return(['Ava Addams','August Ames','Natalia Starr','https://www.xvideos.com/video30486017/realitykings_-_hd_love_-_august_ames_johnny_sins_-_august_fantasy'])
    
