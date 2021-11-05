import random

import cv2
import dlib
import imutils
import numpy as np

# Read image from image path
img = cv2.imread("lucho.jpg", 1)

# set up the 68 point facial landmark detector
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor("shape_predictor_68_face_landmarks.dat")

# convert to grayscale
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# detect faces in the image
faces_in_image = detector(img_gray, 0)

# Process only first image
face = faces_in_image[0]

# assign the facial landmarks
landmarks = predictor(img_gray, face)

# unpack the 68 landmark coordinates from the dlib object into a list
landmarks_list = []
f = open("case1.txt", "w")
for i in range(0, landmarks.num_parts):
    landmarks_list.append((landmarks.part(i).x, landmarks.part(i).y))
    f.write(str(landmarks.part(i).x) + " " + str(landmarks.part(i).y) + "\n")
f.close()
