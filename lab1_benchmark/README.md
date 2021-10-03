on Ubuntu:
```
sudo apt install net-tools

# install git and gcc
sudo apt install git
sudo apt install build-essential
gcc --version

# install docker
# https://docs.docker.com/engine/install/ubuntu/
sudo apt-get remove docker docker-engine docker.io containerd runc
sudo apt-get update
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg

echo \
  "deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io
```
# login to docker hub
```
sudo docker login --username mirackleopinion
```

# clone, build and run code
```
git clone https://github.com/mirackleopinion/university_2grade_aos.git

cd university_2grade_aos/
git pull

cd lab1_benchmark/
gcc -o lab1_benchmark  lab1_benchmark.cpp -lstdc++
./lab1_benchmark
```
# build and push docker image
```
sudo docker build -t  2grade_aos_lab1_benchmark:latest . 
sudo docker run -t 2grade_aos_lab1_benchmark:latest
sudo docker push 2grade_aos_lab1_benchmark:latest
```

