data = [89, 34, 23, 78, 67, 100, 66, 29, 79, 55, 78, 88, 92, 96, 96, 23]
def quicksort(data, left, right): # ��J��ơA�M�q����}�l����m
    if left >= right :            # �p�G����j��k��A�N���Xfunction
        return

    i = left                      # ���䪺�N�z�H
    j = right                     # �k�䪺�N�z�H
    key = data[left]                 # ����I

    while i != j:                  
        while data[j] > key and i < j:   # �q�k��}�l��A������I�p����
            j -= 1
        while data[i] <= key and i < j:  # �q����}�l��A������I�j����
            i += 1
        if i < j:                        # ���k�N�z�H�S���۹J�ɡA������
            data[i], data[j] = data[j], data[i] 

    # �N����I�k���ܥN�z�H�۹J�I
    data[left] = data[i] 
    data[i] = key

    quicksort(data, left, i-1)   # �~��B�z���p�������l�`��
    quicksort(data, i+1, right)  # �~��B�z���j�������l�`��

quicksort(data, 0, len(data)-1)
print(data)