package org.genivi.commonapi.dbus;

import java.util.ArrayList;
import java.util.List;

import org.eclipse.core.resources.IResource;
import org.eclipse.xtext.generator.IFileSystemAccess;
import org.franca.core.franca.FModel;
import org.franca.deploymodel.dsl.fDeploy.FDInterface;
import org.franca.deploymodel.dsl.fDeploy.FDProvider;
import org.franca.deploymodel.dsl.fDeploy.FDTypes;
import org.genivi.commonapi.cmdline.GeneratorInterface;
import org.genivi.commonapi.dbus.generator.FrancaDBusGenerator;

import com.google.inject.Inject;

public class Generator implements GeneratorInterface {

	@Inject
	FrancaDBusGenerator generator;

	public void generate(FModel fModel, List<FDInterface> deployedInterfaces, List<FDTypes> types,
			IFileSystemAccess fileSystemAccess, IResource res) {
		generator.doGenerateComponents(fModel, deployedInterfaces, types, new ArrayList<FDProvider>(),
				fileSystemAccess, res);
	}

}
