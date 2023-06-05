def tele_database():
    phone_data = []
    n = int(input("Enter Number of Clients :- "))
    print("Enter Phone Numbers --\n")
    for i in range(n):
        x = int(input("--> "))
        phone_data.append(x)

    return phone_data

#----------------------------------------------------------------------------------

def hash_function_1(key_ele, m_size):
    h1 = key_ele % m_size
    return h1

def hash_function_2(key_ele):
    h2 = 1 + (key_ele % 11)
    return h2
#----------------------------------------------------------------------------------

def hashtable(ht):
    print(f"\nHash Value      \tKey")
    for j in range(len(ht)):
        if ht[j] != -1:
            print(j,"\t--->",ht[j])
        else:
            print(j)

#----------------------------------------------------------------------------------

phone_database = tele_database()
m = int(input("Enter Hash Table Size :- "))
hash_table = [-1] * m

opt = int(input("If collision occurs which collision resolution technique do you want to use?\n\t1. Linear "
                "Probing\n\t2.Quadratic probing :- "))

#----------------------------------------------------------------------------------

for k in phone_database:
    h_1 = hash_function_1(k, m)
    h_2 = hash_function_2(k)

    if hash_table[h_1] == -1:
        hash_table[h_1] = k
    else:
        if opt == 1:
            while hash_table[h_1] != -1:
                h_1 += 1
            hash_table[h_1] = k
        elif opt == 2:
            for j in range (len(hash_table)):
                new_hash = (h_1 + j* j)%m
                if(hash_table[new_hash]==-1):
                    hash_table[new_hash] = k
                    break

hashtable(hash_table)
#----------------------------------------------------------------------------------