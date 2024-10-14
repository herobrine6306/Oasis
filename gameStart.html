<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Osis Game - Start</title>
  <style>
    body { margin: 0; }
    canvas { display: block; }
    #sky { position: absolute; width: 100%; height: 100%; background: linear-gradient(to top, #87CEEB, #B0E0E6); }
  </style>
</head>
<body>

<div id="sky"></div>

<script src="https://threejs.org/build/three.js"></script>
<script src="https://threejs.org/examples/js/loaders/OBJLoader.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/cannon-es/0.21.0/cannon-es.js"></script>

<script>
  // Scene setup
  const scene = new THREE.Scene();
  const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
  const renderer = new THREE.WebGLRenderer();
  renderer.setSize(window.innerWidth, window.innerHeight);
  document.body.appendChild(renderer.domElement);

  // Physics setup
  const world = new CANNON.World();
  world.gravity.set(0, -9.82, 0);

  // Load floor model
  const loader = new THREE.OBJLoader();
  loader.load('floor.obj', (object) => {
    const floorMaterial = new THREE.MeshStandardMaterial({ color: 0x00ff00 });
    object.traverse((child) => {
      if (child.isMesh) {
        child.material = floorMaterial;
        child.scale.set(10, 1, 10); // Scale the floor to be larger
        child.position.y = -1; // Position the floor correctly
      }
    });
    scene.add(object);

    // Create physics body for the floor
    const floorBody = new CANNON.Body({ mass: 0 });
    floorBody.position.set(0, -1, 0); // Position the physics body
    world.addBody(floorBody);
  });

  // Load player model
  loader.load('player.obj', (object) => {
    const playerMaterial = new THREE.MeshStandardMaterial({ color: 0xff0000 });
    object.traverse((child) => {
      if (child.isMesh) {
        child.material = playerMaterial;
      }
    });
    scene.add(object);

    // Create physics body for the player
    const playerBody = new CANNON.Body({ mass: 1 });
    playerBody.position.set(0, 1, 0); // Position the player above the floor
    world.addBody(playerBody);
  });

  // Set the camera position
  camera.position.z = 5;

  // Animation loop
  function animate() {
    requestAnimationFrame(animate);
    world.step(1 / 60); // Update physics

    // Sync the player mesh with the physics body
    if (playerBody) {
      object.position.copy(playerBody.position);
      object.quaternion.copy(playerBody.quaternion);
    }

    renderer.render(scene, camera);
  }

  animate();
</script>

</body>
</html>
