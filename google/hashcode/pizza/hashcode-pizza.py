import sys
import numpy as np

filename = sys.argv[1]
rows = []
slices = []

with open(filename, 'r') as fin:
    params = fin.readline()
    R, C, L, H = [int(num) for num in params.split()]
    for i in range(R):
        rows.append(fin.readline().rstrip('\n'))
    filled = [[False for i in range(C)] for j in range(R)]
    checked_pairs = [[False for i in range(C)] for j in range(R)]
        
def count_m_t(rs, cs, re, ce):
    tomato = 0
    mushroom = 0
    for i in range(rs, re+1):
        for j in range(cs, ce+1):
            if rows[i][j] == 'T':
                tomato += 1
            else:
                mushroom += 1 
    return tomato, mushroom

def check_empty(rs, cs, re, ce):
    for i in range(rs, re+1):
        for j in range(cs, ce+1):
            if filled[i][j]:
                return False
    return True       

def check_valid(rs, cs, re, ce):
    if (re+1 - rs)*(ce+1 - cs) > H:
        return False
    return check_empty(rs, cs, re, ce)  

def check_rectangle(rs, cs, re, ce):
    if not check_valid(rs, cs, re, ce):
        return False
    tomato, mushroom = count_m_t(rs, cs, re, ce)
    if tomato >= L and mushroom >= L:
        return True
    return False

def row_increase(rs, cs, re, ce):
    r_tomato, r_mushroom = count_m_t(rs, cs, re+1, ce)
    c_tomato, c_mushroom = count_m_t(rs, cs, re, ce+1)
    if abs(r_tomato - r_mushroom) > abs(c_tomato - c_mushroom):
        return False
    return True

def fill(rs, cs, re, ce):
    for i in range(rs, re+1):
        for j in range(cs, ce+1):
            filled[i][j] = True
            
def update_slices(i, rs, cs, re, ce):
    fill(rs, cs, re, ce)
    slices[i] = (rs, cs, re, ce)
    extend_slices(i) 
    
def size_rectangle(rs, cs, re, ce):
    return (re+1-rs)*(ce+1-cs)

def extend_slices():
    i = 0
    while i < len(slices):
    #for i in range(start, len(slices)):
        rs, cs, re, ce = slices[i]
        if size_rectangle(rs, cs, re, ce) + (re+1 - rs) <= H:
            if cs > 0:
                if check_empty(rs, cs-1, re, cs-1):
                    fill(rs, cs-1, re, cs-1)
                    slices[i] = (rs, cs-1, re, ce)  
                    continue
            if ce < C-1:
                if check_empty(rs, ce+1, re, ce+1):
                    fill(rs, ce+1, re, ce+1)
                    slices[i] = (rs, cs, re, ce+1)  
                    continue
        if size_rectangle(rs, cs, re, ce) + (ce+1 - cs) <= H:
            if rs > 0:
                if check_empty(rs-1, cs, rs-1, ce):
                    fill(rs-1, cs, rs-1, ce)
                    slices[i] = (rs-1, cs, re, ce)  
                    continue                       
            if re < R-1:
                if check_empty(re+1, cs, re+1, ce):
                    fill(re+1, cs, re+1, ce)
                    slices[i] = (rs, cs, re+1, ce)  
                    continue
        i += 1
                  
def process_start(rs, cs):
    re = rs
    ce = cs    
    while not check_rectangle(rs, cs, re, ce):
        if ce >= C-1 and re >= R-1:
            return
        if ce >= C-1:
            re += 1
        elif re >= R-1:
            ce += 1
        elif row_increase(rs, cs, re, ce):
            re += 1
        else:
            ce += 1
        if (re+1 - rs)*(ce+1 - cs) > H:
            return
    fill(rs, cs, re, ce)
    slices.append((rs, cs, re, ce))
        
def iterate_rectangles():
    for i in range(R):
        for j in range(C):
            process_start(i, j)
        
iterate_rectangles()

extend_slices()
print(len(slices))
for s in slices:
    print(s[0], s[1], s[2], s[3])
#print(filled)
