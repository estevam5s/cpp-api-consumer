const { spawn } = require('child_process');
const os = require('os');
const fs = require('fs');

const isWindows = os.platform() === 'win32';
const scriptName = isWindows ? 'build_and_run.bat' : 'build_and_run.sh';
const path = isWindows ? `./${scriptName}` : `./${scriptName}`;

fs.chmodSync(scriptName, 0o755);

const executeCpp = () => {
  const child = spawn(path, [], {
    stdio: 'inherit',
    shell: true,
  });

  child.on('exit', (code) => {
    console.log(`Child process exited with code ${code}`);
  });
};

executeCpp();

fs.watch('./src', { recursive: true }, (eventType, filename) => {
  if (filename.endsWith('.cpp') || filename.endsWith('.hpp')) {
    executeCpp();
  }
});
