class CustomControls {
  constructor(camera, domElement) {
    this.camera = camera;
    this.domElement = domElement;

    this.isRotating = false;
    this.rotationSpeed = 0.01;

    this.domElement.addEventListener('mousedown', this.onMouseDown.bind(this));
    this.domElement.addEventListener('mouseup', this.onMouseUp.bind(this));
    this.domElement.addEventListener('mousemove', this.onMouseMove.bind(this));
    this.domElement.addEventListener('wheel', this.onMouseWheel.bind(this));
  }

  onMouseDown(event) {
    this.isRotating = true;
    this.startX = event.clientX;
    this.startY = event.clientY;
  }

  onMouseUp() {
    this.isRotating = false;
  }

  onMouseMove(event) {
    if (!this.isRotating) return;
    const deltaX = event.clientX - this.startX;
    const deltaY = event.clientY - this.startY;
    this.startX = event.clientX;
    this.startY = event.clientY;

    this.camera.rotation.y -= deltaX * this.rotationSpeed;
    this.camera.rotation.x -= deltaY * this.rotationSpeed;
  }

  onMouseWheel(event) {
    this.camera.position.z += event.deltaY * 0.05;
  }
}
