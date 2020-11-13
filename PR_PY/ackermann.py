# coding=UTF-8
class Ackermann:
   
   #attribute 'count' stores number of function calls of ackermann
   count = 0
   
   #attribute 'cache' stores computed values of functions(Memoization)
   cache = {}

   #attribute 'cache_hit' stores number of times cache is used
   cache_hit = 0

   #attribute 'cache_miss' stores number of times cache failed
   cache_miss = 0

   # Function: a0 (Ackermann's Function with Naïve Recursion)
   # Input x: First argument
   # Input y: Second argument
   # Pre-conditions: x>=0 and y>=0
   def a0(self,m,n):
      self.count=self.count+1
      if m==0:
         return n+1
      elif n==0:
         return self.a0(m-1,1)
      else:
         return self.a0(m-1,self.a0(m,n-1))
   
   # Function: a1 (Ackermann's Function with Memoization)
   # Input x: First argument
   # Input y: Second argument
   # Pre-conditions: x>=0 and y>=0
   def a1(self,m,n):
      self.count=self.count+1
      if self.cache.has_key(m) and self.cache[m].has_key(n):
         self.cache_hit = self.cache_hit + 1
         return self.cache[m][n]
      else:
         self.cache_miss = self.cache_miss + 1
         if m==0:
            result=n+1
         elif n==0:
            result=self.a1(m-1,1)
         else:
            result=self.a1(m-1,self.a1(m,n-1))
         if self.cache.has_key(m)==False:
            self.cache[m] = {}
         self.cache[m][n] = result
      return result

   # Function: a2 (Ackermann's Function with Partial Recursion)
   # Input x: First argument
   # Input y: Second argument
   # Pre-conditions: x>=0 and y>=0
   def a2(self,m,n):
      self.count=self.count+1
      if m==0:
         return n+1
      elif m==1:
         return n+2
      elif n==0:
         return self.a2(m-1,1)
      else:
         return self.a2(m-1,self.a2(m,n-1))
   
   # Function: a3 (Ackermann's Function with Memoization + Partial Recursion)
   # Input x: First argument
   # Input y: Second argument
   # Pre-conditions: x>=0 and y>=0
   def a3(self,m,n):
      self.count=self.count+1
      if self.cache.has_key(m) and self.cache[m].has_key(n):
         self.cache_hit = self.cache_hit + 1
         return self.cache[m][n]
      else:
         self.cache_miss = self.cache_miss + 1
         if m==0:
            result=n+1
         if m==1:
            result=n+2
         elif n==0:
            result=self.a3(m-1,1)
         else:
            result=self.a3(m-1,self.a3(m,n-1))
         if self.cache.has_key(m)==False:
            self.cache[m] = {}
         self.cache[m][n] = result
      return result
   
   def run(self,m,n):
      return self.a3(m,n)
   
def print_usage():
   print "USAGE: python %s %s %s\nwhere,\n\tm - first integer parameter to acke\
rmann's function\n\tn - second integer parameter to ackermann's function\nExamp\
le: python %s 2 3"%(sys.argv[0],'m','n',sys.argv[0])

# Main routine
if __name__ == "__main__":
   from datetime import datetime
   import sys
   if len(sys.argv) != 3:
      print_usage()
      exit()
   m = (int)(sys.argv[1])
   n = (int)(sys.argv[2])
   sys.setrecursionlimit(50000)
   start_time = datetime.now()
   ackermann = Ackermann()
   print 'ackermann(%d,%d): %d'%(m,n,ackermann.run(m,n))
   end_time = datetime.now()
   time_diff = end_time - start_time
   print 'execution time: %s'%time_diff
   print 'Number of calls: %d'%ackermann.count
   if ackermann.cache != {}:
      print 'Cache Hit count: %d'%ackermann.cache_hit
      print 'Cache Miss count: %d'%ackermann.cache_miss
print 'Cache Hit ratio: %.2f'%((float)(ackermann.cache_hit)/ackermann.cache_miss*100)
