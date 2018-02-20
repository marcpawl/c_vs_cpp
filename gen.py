
import random
import sys

alpha_num="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
alpha_num_size=len(alpha_num)

def random_string(size) :
  result=""
  while len(result) < size :
    r = int(random.random() * alpha_num_size)
    result=result+alpha_num[r]
  return result
 

def generate_email() :
  name_length = random.uniform(4,10)
  domain_length = random.uniform(4,20)
  name=random_string(name_length)
  domain=random_string(domain_length)
  email=name + "@" + domain 
  return email
  

data=open("data.txt", "w")
seed=int(sys.argv[1])
nb_emails=int(sys.argv[2])
random.seed(seed)
email_nb=0
data.write('"');
while email_nb < nb_emails:
  data.write(generate_email())
  email_nb = email_nb + 1
  if email_nb < nb_emails :
    data.write(',')
data.write('";');

