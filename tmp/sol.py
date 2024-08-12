import re

def is_minimum_length(password):
    return len(password) >= 8

def has_uppercase(password):
    return bool(re.search(r'[A-Z]', password))

def has_lowercase(password):
    return bool(re.search(r'[a-z]', password))

def has_digit(password):
    return bool(re.search(r'\d', password))

def has_special_char(password):
    return bool(re.search(r'[!@#$%^&*()]', password))

def has_mixed_3(password) :
    mixed = 0
    mixed += bool(re.search(r'[A-Z]', password))
    mixed += bool(re.search(r'[a-z]', password))
    mixed += bool(re.search(r'\d', password))
    mixed += bool(re.search(r'[!@#$%^&*()]', password))
    return mixed >= 3

def count_requirements(password):
    count = 0
    if is_minimum_length(password):
        count += 1
    if has_uppercase(password):
        count += 1
    if has_lowercase(password):
        count += 1
    if has_digit(password):
        count += 1
    if has_special_char(password):
        count += 1
    if has_mixed_3(password):
        count += 1
    return count >= 5

def solution(password):
    # 비밀번호가 5개 이상의 요구사항을 충족하는지 확인
    print(f"password : {password}, met : {count_requirements(password)}")
    return count_requirements(password) >= 5  
