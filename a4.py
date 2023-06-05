def createSet():
    n=int(input("Enter number of Elements in set :- "))
    s = []
    for i in range(n) :
        e = int(input("Enter Element->"))
        s.append(e) 
    return s

#----------------------------------------------------------------------------------------------
def add( s, e ):                  
        if e not in s :
            s.append( e )

#-------------------------------------------
def remove( s, e ):
        if e in s:
            s.remove(e)
#-------------------------------------------

def intersect( s1, s2 ):
        newSet = []
        for i in range(len(s1)) :
            for j in range(len(s2)) :
                if s1[i] == s2[j] :
                    add(newSet, s1[i])
        return newSet
#-------------------------------------------

def union( s1, s2 ):                 
        newSet = s1  
        for e in s2 :
            if e not in s1 :
                add(newSet,e)
        return newSet

#-------------------------------------------
def isSubsetOf( s1, s2 ):           
     for e in s2 :
         if e not in s1 :
             return False
     return True 

#-------------------------------------------
def isProperSubset( s1, s2 ):
    if isSubsetOf(s1,s2) and not isSubsetOf(s2,s1):
        return True
    return False
#-------------------------------------------

def difference( s1, s2 ):
        newSet = []
        for e in s1 :
            if e not in s2:
                add(newSet,e)
        return newSet

#--------------------------------------------------------------------------------------------
def display(s):
    string = "\n{ "
    for i in range(len(s)):
        string = string + str(s[i])
        if i != len(s)-1:
            string = string + " , "
    string = string + " }\n"
    return string

#---------------------------------------------------------------------------------------------
choice = 0
print("Create Set A")
s1 = createSet()
print(display(s1))

while choice != 10:
    print("Menu")
    print("1.Add")
    print("2.Remove")
    print("3.Contains")
    print("4.Size")
    print("5.Intersection")
    print("6.Union")
    print("7.Difference")
    print("8.Subset")
    print("9.Proper Subset")
    print("10.Exit")
    choice = int(input("Enter Choice :- "))

#-------------------------------------------
    if choice==1:
        e = int(input("Enter Number to Add :- "))
        add(s1,e)
        print(display(s1))

    elif choice==2:
        e = int(input("Enter Number to Remove :- "))
        remove(s1,e)
        print(display(s1))

    elif choice==3:
        e = int(input("Enter Number to Search : "))
        if e in s1:
            print("Number Present in Set.")
        else:
            print("Number is not Present in Set.")

        print(display(s1))

    elif choice==4:
        print("Set Contains {} elements".format(len(s1),"\n"))


    elif choice==5:
        print("Create a Set B for doing Intersection Operation.")
        s2 = createSet()
        s3 = intersect(s1,s2)
        print("Set A = ",display(s1))
        print("Set B = ",display(s2))
        print("Intersection = ",display(s3),"\n")

    elif choice==6:
        print("Create a Set B for doing Union Operation.")
        s2 = createSet()
        s3 = union(s1,s2)
        print("Set A = "+display(s1))
        print("Set B = "+display(s2))
        print("Union = "+display(s3),"\n")

    elif choice==7:
        print("Create a Set B for calculating Set Difference.")
        s2 = createSet()
        s3 = difference(s1,s2)
        print("Set A = "+display(s1))
        print("Set B = "+display(s2))
        print("Difference = "+display(s3),"\n")

    elif choice==8:
        print("Create a Set B for checking Subset or not.")
        s2 = createSet()
        isSubset = isSubsetOf(s1,s2)
        print("Set A = "+display(s1))
        print("Set B = "+display(s2))
        if isSubset:
            print("Set B is the Subset of Set A.")
        else:
            print("Set B is not a Subset of Set A.")

    elif choice==9:
        print("Create a Set B for checking ProperSubset or not.")
        s2 = createSet()
        isProperSub = isProperSubset(s1,s2)
        print("Set A = "+display(s1))
        print("Set B = "+display(s2))
        if isProperSub:
            print("Set B is the Proper Subset of Set A.")
        else:
            print("Set B is not a Proper Subset of Set A.")

    elif choice==10:
        break
#----------------------------------------------------------------------------------------------