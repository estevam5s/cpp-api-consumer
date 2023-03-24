const { exec } = require('child_process');

exec('./build/api_consumer', (error, stdout, stderr) => {
  if (error) {
    console.error(`Erro ao executar o programa C++: ${error.message}`);
    return;
  }

  if (stderr) {
    console.error(`Erro de stderr: ${stderr}`);
    return;
  }

  console.log(`Saída do programa C++:\n${stdout}`);
});
