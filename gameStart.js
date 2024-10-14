// Importing necessary libraries
import * as THREE from 'https://cdn.jsdelivr.net/npm/three@0.130.1/build/three.module.js';
import { OrbitControls } from 'https://cdn.jsdelivr.net/npm/three@0.130.1/examples/jsm/controls/OrbitControls.js';
import { OBJLoader } from 'https://cdn.jsdelivr.net/npm/three@0.130.1/examples/jsm/loaders/OBJLoader.js';

// Setting up scene, camera, and renderer
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Adding background
const skyColor = new THREE.Color(0x87CEEB); // Sky blue color
scene.background = skyColor;

// Load the floor model
const objLoader = new OBJLoader();
objLoader.load('floor.obj', (object) => {
  object.scale.set(100, 1, 100); // Adjust the scale as necessary
  object.position.y = -0.5; // Position it correctly
  scene.add(object);
}, undefined, (error) => {
  console.error('An error happened while loading floor.obj', error);
});

// Load the player model
let player;
objLoader.load('player.obj', (object) => {
  player = object;
  player.position.y = 1; // Adjust position to be above the floor
  scene.add(player);
}, undefined, (error) => {
  console.error('An error happened while loading player.obj', error);
});

// Orbit controls for the camera
const controls = new OrbitControls(camera, renderer.domElement);
camera.position.set(0, 5, 10);
controls.update();

// Animation loop
function animate() {
  requestAnimationFrame(animate);
  if (player) {
    player.rotation.y += 0.01; // Rotate the player model if needed
  }
  controls.update();
  renderer.render(scene, camera);
}

animate();

