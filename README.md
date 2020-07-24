# ORB_SLAM_vocab-build

The state of the art SLAM algorithms like ORB SLAM use a bag-of-words approach to create a vocabulary of words which can be used for the purpose of place recognition and detection of loop closures. The default dictionary ```ORBvoc.txt``` is sufficient in most of the cases of indoor and outdoor environments, though it is observed that the performance drops in a highly specialised environment like underwater or non common environments. No proper instructions have been provided which can be used to create your own custom vocabulary. Thus this repository contains step by step procedure to create your own vocabulary using custom dataset which can be directly used for ORB SLAM.

This repository can be used to create custom bag of words vocabulary which can be directly used for ORB SLAM/ORB SLAM2.
It consists of 2 major sub-folders:  

1.DBoW2 (Forked from [dorian3d/DBoW2](https://github.com/dorian3d/DBoW2))  
2.ORB_SLAM_txt (modified and used from [ORB_SLAM2](https://github.com/raulmur/ORB_SLAM2))

Here is the step by step procedure to build your own bag of words vocabulary and save it as .txt file format (which is required for ORB_SLAM):

## 1. Prerequisites
We have tested the library in **Ubuntu 12.04**, **14.04**, **16.04** & **18.04**, but it should be easy to compile in other platforms.
### 1.1 C++11 or C++0x Compiler
We use the new thread and chrono functionalities of C++11.
### 1.2 OpenCV
We use [OpenCV](http://opencv.org) to manipulate images and features. Dowload and install instructions can be found at: http://opencv.org. **Required at leat 2.4.3. Tested with OpenCV 2.4.11 and OpenCV 3.2**.


## 2. Installation

### 2.1. Clone the repository
```
cd ~/
git clone https://github.com/manthan99/ORB_SLAM_vocab-build.git
```

### 2.2. Compile *DBoW2*
```
cd ~/ORB_SLAM_vocab-build/DBoW2/
mkdir build
cd build
cmake ..
make -j
```
### 2.3. Compile *ORB_SLAM_txt*

   2.3.1 Compile thirdparty DBoW2  
```
cd ~/ORB_SLAM_vocab-build/ORB_SLAM_txt/Thirdparty/DBoW2/
mkdir build
cd build
cmake ..
make -j
```

   2.3.2 Compile Vocab
```
cd ~/ORB_SLAM_vocab-build/ORB_SLAM_txt/
mkdir build
cd build
cmake ..
make -j
```


## 3. Creating a vocabulary as yml

  * We will use demo.cpp (```~/ORB_SLAM_vocab-build/DBoW2/demo/demo.cpp```) to first create a vocabulary and save it as a yml file.  
  * Please go through the publication given here [dorian3d/DBoW2](https://github.com/dorian3d/DBoW2) to understand about the branching factor(K) and levels(L).
  * The ORB SLAM uses a vocabulary having branching factor as 10 and depth levels as 6, thus creating a dictionary of 10^6 (1 Million) words.
  * You will require a dataset of images for creating the vocabulary. The images **n** must be named as *image0.png, image1.png ... image**n**.png*. Copy the dataset to the following folder: ```~/ORB_SLAM_vocab-build/DBoW2/demo/images/```
  * Alternatively, if you are using ROS and have a bag file which you intend to use for training, you may use the *bag_to_img* launch file to create a dataset of images from the bag file. In the launch file, do the following changes
    1. Replace ```~/castle_ruins_vocab.bag``` with the location of your bag file.  
    2. Replace ```/airsim_node/drone_1/front_center/Scene``` with the image topic
    3. You may set the output location in the param ```filename_format```. Default is ```~/ORB_SLAM_vocab-build/DBoW2/demo/images/image%i.png```, which will directly export the images to the required images folder.
    4. You may set the param ```"_sec_per_frame"``` to your required frequency. Setting it to **0.1** will extract the images at 10 Hz.
  * Open the ```demo.cpp``` to edit the values of **K** & **L** in line no. *105*. 
  * Change the value of *NIMAGES* in line *35* to the no. of images in the training dataset.
  * You may change the output name of the vocabulary file from line no. *136* and *147*. Default is ```"castle_ruins.yml.gz"```.
  * Now we need to create the executable for demo.cpp
     ```
     cd ~/ORB_SLAM_vocab-build/DBoW2/build
     cmake ..
     make -j
     ```
  * Execute *demo*. This will create a vocabulary and save it as a yml file. It may take upto a few hours if you have images in the order of *10^3*.
     ```
     ./demo
     ```

## 4. Converting yml vocabulary to txt

  * This is a necessary step in order to use the vocabulary for ORB_SLAM. ORB_SLAM does not support yml file format.
  * Copy the created yml file (default - ```castle_ruins.yml.gz```) to the following folder - ```~/ORB_SLAM_vocab-build_copy/ORB_SLAM_txt/Vocab```
  * Edit the input and output file in line no. *20* and *21* of ```covert_to_txt.cpp```(```~/ORB_SLAM_vocab-build/ORB_SLAM_txt/Vocab/convert_to_txt.cpp```)
  * Create a executable and run-
     ```
     cd ~/ORB_SLAM_vocab-build/ORB_SLAM_txt/build/
     make -j
     cd ~/ORB_SLAM_vocab-build/ORB_SLAM_txt/Vocab
     ./convert_to_txt
     ```
  * This will create the required vocabulary in txt file format. It will just take a few seconds.

## 5. Examples
 
  * A couple of vocabulary files have been provided in the Example_Vocab folder(```~/ORB_SLAM_vocab-build/ORB_SLAM_txt/Example_Vocab```).
    1. ORBvoc.txt.tar.gz (The default vocabulary for ORB SLAM)
    2. Castle_Ruins_voc.zip (Vocabulary for the Castle Ruins Airsim Environment)([Link](http://patelmanthan.in/castle-ruins-airsim/))
  
